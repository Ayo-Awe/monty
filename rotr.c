#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

/**
 * rotr_handler - bottom of stack moves to top
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void rotr_handler(stack_t **stack,
				  unsigned int line_number __attribute__((unused)))
{
	stack_t *current = NULL;
	int prev = 0;
	int tmp = 0;

	if (!stack || *stack == NULL)
		return;

	current = *stack;
	prev = current->n;

	/* Stack values down */
	while (current->next)
	{
		tmp = current->n;

		/* Set value to value of previous node */
		if (current->prev)
			current->n = prev;

		/* Set previous value to value of this node */
		prev = tmp;
		current = current->next;
	}

	/* Set value of top of stack to value of last element */
	(*stack)->n = current->n;

	/* Set value of last element to value of previous node */
	current->n = prev;
}
