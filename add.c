#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void handle_add_error(int line_number, stack_t **stack);
/**
 * add_handler - adds top two elements, stores the result
 * in the second and pops the first
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void add_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *one = NULL;
	stack_t *two = NULL;
	int sum = 0;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		handle_add_error(line_number, stack);

	one = *stack;
	two = one->next;

	sum = one->n + two->n;
	two->n = sum;

	pop_handler(stack, line_number);
}

/**
 * handle_add_error - frees stack, prints error and exits program
 * @line_number: current line number of the file
 * @stack: head of the stack
 *
 * Return: void
 */
void handle_add_error(int line_number, stack_t **stack)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
