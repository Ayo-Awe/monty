#include <stdio.h>
#include <stdlib.h>
/**
 * handle_error - prints an error message to stderr and
 * exits the program
 * @msg: string pointer to error message
 *
 * Return: void
 */
void handle_error(char *msg)
{
	if (!msg)
		msg = "Error";

	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
