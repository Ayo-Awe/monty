#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

/**
 * rotl_handler - top of stack to the buttom
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void rotl_handler(stack_t **stack,
				  unsigned int line_number __attribute__((unused)))
{
	stack_t *current = NULL;
	int top_value = 0;

	if (!stack || *stack == NULL)
		return;

	current = *stack;

	top_value = current->n;

	/* Move stack values up */
	while (current->next)
	{
		current->n = current->next->n;
		current = current->next;
	}

	/* Set value of last element to top value */
	current->n = top_value;
}
