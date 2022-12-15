#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void handle_swap_error(int line_number, stack_t **stack);
/**
 * swap_handler - swap top two elements on the stack
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void swap_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *one = NULL;
	stack_t *two = NULL;
	int tmp = 0;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		handle_swap_error(line_number, stack);

	one = *stack;
	two = one->next;

	tmp = one->n;
	one->n = two->n;
	two->n = tmp;
}

/**
 * handle_swap_error - frees stack, prints error and exits program
 * @line_number: current line number of the file
 * @stack: head of the stack
 *
 * Return: void
 */
void handle_swap_error(int line_number, stack_t **stack)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
