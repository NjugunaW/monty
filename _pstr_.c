#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to a pointer to a struct
 * @line_number: unsigned int
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *curr = *stack;

	while (curr)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		putchar((char) curr->n);
		curr = curr->next;
	}
	putchar('\n');
}
