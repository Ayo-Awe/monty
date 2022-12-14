#ifndef _MONTY_H_
#define _MONTY_H_
extern char buffer[1000];
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
 * struct operation - opcode and its argument
 * @opcode: the opcode
 * @arg: argument for opcode
 *
 * Description: opcode and its argument
 */
typedef struct operation_s
{
	char *opcode;
	int arg;
} operation_t;
void handle_error(char *msg);
void push_handler(stack_t **stack, unsigned int line_number);
char *parse_opcode(char *line);
void (*get_handler(char *opcode))(stack_t **stack, unsigned int line_number);
#endif
