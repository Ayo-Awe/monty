#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void handle_mul_error(int line_number, stack_t **stack);
/**
 * mul_handler - multiplies top two elements, stores the result
 * in the second and pops the first
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void mul_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *one = NULL;
	stack_t *two = NULL;
	int mul = 0;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		handle_mul_error(line_number, stack);

	one = *stack;
	two = one->next;

	mul = one->n * two->n;
	two->n = mul;

	pop_handler(stack, line_number);
}

/**
 * handle_mul_error - frees stack, prints error and exits program
 * @line_number: current line number of the file
 * @stack: head of the stack
 *
 * Return: void
 */
void handle_mul_error(int line_number, stack_t **stack)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
