#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * nop_handler - does nothing
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void nop_handler(stack_t **stack __attribute__((unused)),
				 unsigned int line_number __attribute__((unused)))
{
	return;
}
