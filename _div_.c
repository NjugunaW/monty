#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * div_elements - divides second top element by top element of stack
 * @stack: pointer to a pointer to a struct
 * @line_number: unsigned integer
 *
 * Return: void
 */
void div_elements(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
		;
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	_pop_(stack, line_number);/*For top node*/
	(*stack)->n = result;
}
