#include "monty.h"

/**
 * queue_handler - sets mode
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void queue_handler(stack_t **stack __attribute__((unused)),
				   unsigned int line_number __attribute__((unused)))
{
	/* Set mode to queue */
	myglobals.mode = 1;
}
