#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void handle_mod_error(int line_number, stack_t **stack, char *msg);
/**
 * mod_handler - finds mod of second element by top element, stores the result
 * in the second and pops the first
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void mod_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *one = NULL;
	stack_t *two = NULL;
	int div = 0;

	/* If stack has less than two elements */
	if (!stack || *stack == NULL || (*stack)->next == NULL)
		handle_mod_error(line_number, stack, "can't mod, stack too short");

	/* Division by zeror is not allowed */
	if ((*stack)->n == 0)
		handle_mod_error(line_number, stack, "division by zero");

	one = *stack;
	two = one->next;

	div = two->n % one->n;
	two->n = div;

	pop_handler(stack, line_number);
}

/**
 * handle_mod_error - frees stack, prints error and exits program
 * @line_number: current line number of the file
 * @stack: head of the stack
 * @msg: error message
 *
 * Return: void
 */
void handle_mod_error(int line_number, stack_t **stack, char *msg)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%u: %s\n", line_number, msg);
	exit(EXIT_FAILURE);
}
