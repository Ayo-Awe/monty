#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

global_t myglobals;

void handle_instruction_error(int line_number, stack_t **stack, char *code);

/**
 * main - Entry point for monty interpreter
 * @argc: integer representing number of arguments
 * @argv: array of pointers of arguments
 *
 * Return: void
 */
int main(int argc, char *argv[])
{
	FILE *source;
	char buffer[1000];
	int current_line = 1;
	void (*handler)(stack_t **stack, unsigned int line_number);
	char *code;
	stack_t *head = NULL;

	myglobals.buffer = buffer;
	if (argc != 2)
		handle_error("USAGE: monty file", &head);

	source = fopen(argv[1], "r");

	if (!source)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	myglobals.file = source;

	/* Main interpreter execution loop */
	while (fgets(buffer, 1000, source))
	{
		/* Get rid of new line */
		buffer[strlen(buffer) - 1] = ' ';
		code = parse_opcode(buffer, &head);

		if (!code)
		{
			current_line++;
			continue;
		}

		handler = get_handler(code);

		if (!handler)
			handle_instruction_error(current_line, &head, code);

		free(code);
		handler(&head, current_line);

		current_line++;
	}

	free_stack(&head);
	fclose(source);

	return (0);
}

/**
 * handle_instruction_error - prints error message on incorrect instruction
 * @line_number: current line number
 * @stack: address of head of stack
 * @code: opcode being executed
 *
 * Return: void
 */
void handle_instruction_error(int line_number, stack_t **stack, char *code)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, code);
	free(code);
	exit(EXIT_FAILURE);
}
