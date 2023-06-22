#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push_elem - pushes an element to the stack
 * @stack: pointer to a pointer to a struct
 * @line_number: unsigned int
 *
 * Return: void
 */
void push_elem(stack_t **stack, unsigned int line_number)
{
	char *c = universal.argument;

	if ((digit_checker(c)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (universal.data_struct == 1)
	{
		if (!_node_adds(stack, atoi(universal.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_opcode(stack, atoi(universal.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
