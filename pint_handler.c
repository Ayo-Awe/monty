#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void handle_pint_error(int line_number, stack_t **stack);
/**
 * pint_handler - prints the value of the top stack
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void pint_handler(stack_t **stack, unsigned int line_number)
{
	/* Check if stack is empty */
	if (!stack || *stack == NULL)
		handle_pint_error(line_number, stack);

	/* Print top of stack */
	printf("%d\n", (*stack)->n);
}

/**
 * handle_pint_error - frees stack, prints error and exits program
 * @line_number: current line number of the file
 * @stack: head of the stack
 *
 * Return: void
 */
void handle_pint_error(int line_number, stack_t **stack)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
