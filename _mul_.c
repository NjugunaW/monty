#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mul_vals - muls the second top element with the top element of the stack
 * @stack: pointer to a pointer to a struct
 * @line_number: unsigned integer
 * Return: void
 */
void mul_vals(stack_t **stack, unsigned int line_number)
{
	int output;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	output = ((*stack)->next->n) * ((*stack)->n);
	_pop_(stack, line_number);/*For top node*/
	(*stack)->n = output;
}
