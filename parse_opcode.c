#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * parse_opcode - parses opcode and return char containg opcode
 * @line: string pointer containing current executing line
 * @stack: pointer to head of stack
 *
 * Return: string containg opcode or NULL
*/
char *parse_opcode(char *line, stack_t **stack)
{
	char *dup_line = NULL;
	char *token = NULL;

	if (!line)
		exit(EXIT_FAILURE);

	dup_line = strdup(line);

	if (!dup_line)
		handle_error("Error: malloc failed", stack);

	/* Get rid of new line */
	dup_line[strlen(dup_line) - 1] = ' ';

	/* Get opcode */
	token = strtok(dup_line, " ");

	/* No instruction on the line */
	if (!token)
	{
		free(dup_line);
		return (token);
	}

	/* Return a duplicate of token */
	token = strdup(token);

	free(dup_line);

	/* Malloc failure */
	if (!token)
		handle_error("Error: malloc failed", stack);

	return (token);
}
