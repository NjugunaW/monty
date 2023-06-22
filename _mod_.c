#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mod_der - calculates the remainder of the division btwn two nums
 * @stack: pointer to a pointer to a struct
 * @line_number: unsigned integer
 * Return: void
 */
void mod_der(stack_t **stack, unsigned int line_number)
{
	int output;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	output = ((*stack)->next->n) % ((*stack)->n);
	_pop_(stack, line_number);/*For top node*/
	(*stack)->n = output;
}
