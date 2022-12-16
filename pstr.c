#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * pstr_handler - prints stack as a sequence of characters
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void pstr_handler(stack_t **stack,
				  unsigned int line_number __attribute__((unused)))
{
	stack_t *current = NULL;

	if (stack)
		current = *stack;

	while (current)
	{
		/* Out of range */
		if (current->n > 127 || current->n < 0)
			break;

		/* Value of element is 0 */
		if (current->n == 0)
			break;

		/* Print character */
		putchar(current->n);

		/* Move to next element in the stack */
		current = current->next;
	}

	putchar('\n');
}
