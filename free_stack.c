#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - frees a malloc'd stack_t
 * @stack: pointer to head of stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *current;
	stack_t *next;

	if (!stack)
		return;

	if (*stack == NULL)
		return;

	current = *stack;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
