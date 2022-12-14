#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char buffer[1000];

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
	int BUFFER_SIZE = 1000;
	int current_line = 1;
	void (*handler)(stack_t * *stack, unsigned int line_number);
	char *code;
	stack_t *head = NULL;

	if (!argv[0])
		return (0);

	if (argc != 2)
		handle_error("USAGE: monty file");

	source = fopen(argv[1], "r");

	if (!source)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Main interpreter execution loop */
	while (fgets(buffer, BUFFER_SIZE, source))
	{
		code = parse_opcode(buffer);

		if (!code)
			continue;

		handler = get_handler(code);
		if (!handler)
		{
			fprintf(stderr, "L%d: unknown instruction %s", current_line, code);
			exit(EXIT_FAILURE);
		}

		handler(&head, current_line);

		current_line++;
		free(code);
	}

	fclose(source);

	return (0);
}
