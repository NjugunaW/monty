#include "monty.h"

/**
* rotate_r - rotates the stack to the bottom.
* @stack: double pointer toa struct
* @line_number: unsigned int
*
* Return: void
*/
void rotate_r(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom;
	stack_t *prev;

	(void) line_number;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
