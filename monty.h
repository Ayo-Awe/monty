#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - opcode and its argument
 * @buffer: buffer
 * @file: argument for opcode
 *
 * Description: opcode and its argument
 */
typedef struct global_s
{
	char *buffer;
	FILE *file;
} global_t;

extern global_t myglobals;
void handle_error(char *msg, stack_t **stack);
void push_handler(stack_t **stack, unsigned int line_number);
char *parse_opcode(char *line, stack_t **stack);
void (*get_handler(char *opcode))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void pall_handler(stack_t **stack, unsigned int line_number);
void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
#endif
