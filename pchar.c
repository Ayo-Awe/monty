#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void handle_pchar_error(int line_number, stack_t **stack, char *msg);
/**
 * pchar_handler - finds mod of second element by top
 * element, stores the result
 * in the second and pops the first
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void pchar_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;

	/* If stack has less than two elements */
	if (!stack || *stack == NULL)
		handle_pchar_error(line_number, stack, "can't pchar, stack empty");

	head = *stack;

	/* Division by zeror is not allowed */
	if (head->n > 127 || head->n < 0)
		handle_pchar_error(line_number, stack,
						   "can't pchar, value out of range");

	printf("%c\n", head->n);
}

/**
 * handle_pchar_error - frees stack, prints error and exits program
 * @line_number: current line number of the file
 * @stack: head of the stack
 * @msg: error message
 *
 * Return: void
 */
void handle_pchar_error(int line_number, stack_t **stack, char *msg)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%u: %s\n", line_number, msg);
	exit(EXIT_FAILURE);
}
