#include "monty.h"

/**
 * _pall_ - prints all the vals on the stack, from the top of the stack
 * @stack: pointer to a pointer to astruct
 * @line_number: unsigned integer
 *
 * Return: void
 */
void _pall_(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_show(*stack);
}
