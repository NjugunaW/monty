#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

#define INSTRUCTIONS              \
	{                           \
		{"push", push_elem},       \
		    {"pall", _pall_},   \
		    {"pint", pint},   \
		    {"pop", _pop_},     \
		    {"swap", swap_elements},   \
		    {"nop", _nop_},     \
		    {"div", div_elements},    \
		    {"mul", mul_vals},    \
		    {"add", add_elements},    \
		    {"sub", sub_elements},    \
		    {"mod", mod_der},     \
		    {"pchar", _pchar}, \
		    {"pstr", pstr},   \
		    {"rotl", rotate_l},   \
		    {"rotr", rotate_r},   \
		{                     \
			NULL, NULL      \
		}                     \
	}

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
 * struct instruction_s - _opcode_ and its function
 * @_opcode_: the _opcode_
 * @f: function to handle the _opcode_
 *
 * Description: _opcode_ and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *_opcode_;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct aide - argument for the current _opcode_
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: uni structure used to pass data around the functions easily
*/
typedef struct aide
{
	int data_struct;
	char *argument;
} aide;
aide universal;


stack_t *_node_adds(stack_t **stack, const int n);
stack_t *queue_opcode(stack_t **stack, const int n);
void stack_empty(stack_t *stack);
size_t stack_show(const stack_t *stack);

void push_elem(stack_t **stack, unsigned int line_number);
void _pall_(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap_elements(stack_t **stack, unsigned int line_number);
void _pop_(stack_t **stack, unsigned int line_number);
void _nop_(stack_t **stack, unsigned int line_number);

void div_elements(stack_t **stack, unsigned int line_number);
void add_elements(stack_t **stack, unsigned int line_number);
void sub_elements(stack_t **stack, unsigned int line_number);
void mul_vals(stack_t **stack, unsigned int line_number);
void mod_der(stack_t **stack, unsigned int line_number);

void _pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotate_l(stack_t **stack, unsigned int line_number);
void rotate_r(stack_t **stack, unsigned int line_number);

void _opcode_(stack_t **stack, char *str, unsigned int line_number);

int digit_checker(char *string);
int num_checker(char *str);

#endif /* MONTY_H */
