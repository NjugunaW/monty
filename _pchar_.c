#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include <ctype.h>

/**
 * _pchar - prints the char at the top of the stack.
 * @stack: pointer to a pointer to a struct
 * @line_number: unsigned int
 *
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n >= 0 && (*stack)->n <= 127) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
