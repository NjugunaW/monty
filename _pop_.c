#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* _pop_ - removes the top element of the stack
* @stack: pointer to a pointer to a struct
* @line_number: line number for error messages
*
* Return: void
*/
void _pop_(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
