#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * handle_error - prints an error message to stderr and
 * exits the program
 * @msg: string pointer to error message
 * @stack: pointer to head of stack
 *
 * Return: void
 */
void handle_error(char *msg, stack_t **stack)
{
	if (!msg)
		msg = "Error";

	free_stack(stack);

	if (myglobals.file)
		fclose(myglobals.file);

	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
