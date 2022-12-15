#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void handle_pop_error(int line_number, stack_t **stack);
/**
 * pop_handler - removes top element on the stack
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top = NULL;

	if (!stack || *stack == NULL)
		handle_pop_error(line_number, stack);

	new_top = (*stack)->next;

	if (new_top)
		new_top->prev = NULL;

	/* Free old top value */
	free(*stack);

	*stack = new_top;
}

/**
 * handle_pop_error - frees stack, prints error and exits program
 * @line_number: current line number of the file
 * @stack: head of the stack
 *
 * Return: void
 */
void handle_pop_error(int line_number, stack_t **stack)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}
