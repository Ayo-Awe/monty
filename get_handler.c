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
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}};

	while (instructions[i].opcode)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}
