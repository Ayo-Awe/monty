#include "monty.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * get_handler - returns handler for specified opcode
 * @opcode: string pointer for opcode
 *
 * Return: function pointer to handle opcode instruction or NULL
*/
void (*get_handler(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{NULL, NULL}};

	while (instructions[i].opcode)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}
