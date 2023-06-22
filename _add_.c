#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * add_elements -  a function that adds the first two ndes of a stack
 * @stack: pointer to a pointer to a struct
 * @line_number: integer
 *
 * Return: void
 */
void add_elements(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	_pop_(stack, line_number); /*For top node*/
	(*stack)->n = result;
}
