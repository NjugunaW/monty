#include "monty.h"

/**
* rotate_l - rotates the stack to the top.
* @stack: double pointer to a struct
* @line_number: unsigned int
*
* Return: void
*/
void rotate_l(stack_t **stack, unsigned int line_number)
{
	stack_t *lft;
	stack_t *rgt;

	(void) line_number;
	if (!stack || !*stack || !(*stack)->next)
		return;

	lft = rgt = *stack;

	while (rgt->next)
		rgt = rgt->next;
	rgt->next = lft;
	lft->prev = rgt;
	*stack = lft->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
