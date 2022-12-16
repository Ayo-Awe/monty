#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

void add_node(stack_t **head, int element);
int _isdigit(char *s_num);
void handle_push_error(int line_number, stack_t **stack);

/**
 * push_handler - push an integer onto the stack
 * @stack: pointer to head of the stack
 * @line_number: current line number
 *
 * Return: void
 */
void push_handler(stack_t **stack, unsigned int line_number)
{
	char *arg_s;
	int arg = 0;

	/* Get arg from buffer */
	strtok(myglobals.buffer, " ");
	arg_s = strtok(NULL, " ");

	if (!arg_s)
		handle_push_error(line_number, stack);

	if (_isdigit(arg_s) == -1)
		handle_push_error(line_number, stack);

	/* Parse arg to int */
	arg = atoi(arg_s);

	/* Parse error */
	if (arg_s[0] != '0' && arg == 0)
		handle_push_error(line_number, stack);

	add_node(stack, arg);
}

/**
 * add_node - adds a node to the top of the stack
 * @head: head of the stack
 * @element: element to add to stack
 *
 * Return: void
 */
void add_node(stack_t **head, int element)
{
	stack_t *current;
	stack_t *new;

	if (!head)
		return;

	new = malloc(sizeof(stack_t));

	if (!new)
		handle_error("Error: malloc failed", head);

	new->n = element;
	new->prev = NULL;
	new->next = NULL;

	/* Stack is empty */
	if (*head == NULL)
	{
		*head = new;
		return;
	}

	/* Store address of old head in temporary variable */
	current = *head;

	/* Set head to point to new node */
	*head = new;

	/* Make new node head */
	new->next = current;
	current->prev = new;
}

/**
 * handle_push_error - frees stack, prints error and exits program
 * @line_number: current line number of the file
 * @stack: head of the stack
 *
 * Return: void
 */
void handle_push_error(int line_number, stack_t **stack)
{
	fclose(myglobals.file);
	free_stack(stack);
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * _isdigit - checks if a string is made of only digits
 * @s_num: string
 *
 * Return: 1 if digit or -1
 */
int _isdigit(char *s_num)
{
	int i = 0;

	if (!s_num)
		return (-1);

	/* Ignore negative symbol*/
	if (*s_num == '-')
		s_num++;

	while (s_num[i])
	{
		if (isdigit(s_num[i]) == 0)
			return (-1);

		s_num++;
	}

	return (1);
}
