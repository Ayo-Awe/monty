#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * pall_handler - print all elements on the stack
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void pall_handler(stack_t **stack,
unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	if (!stack || *stack == NULL)
		return;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
