#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * sub_elements -  subs the top element from the second top element of stack
 * @stack: double pointer to a struct
 * @line_number: unsigned integer
 *
 * Return: void
 */
void sub_elements(stack_t **stack, unsigned int line_number)
{
	int output;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	output = ((*stack)->next->n) - ((*stack)->n);
	_pop_(stack, line_number);
	(*stack)->n = output;
}
