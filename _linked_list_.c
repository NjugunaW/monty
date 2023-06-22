#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * queue_opcode - sets the format of the data to a stack (LIFO)
 * @stack: pointer to a pointer to a struct
 * @n: integer
 *
 * Return: frsh node, if malloc fails, the function will return NULL
 */
stack_t *queue_opcode(stack_t **stack, const int n)
{
	stack_t *frsh = malloc(sizeof(stack_t));
	stack_t *curr = *stack;

	if (!frsh)
	{
		free(frsh);
		return (NULL);
	}
	frsh->n = n;

	if (!*stack)
	{
		frsh->next = NULL;
		frsh->prev = NULL;
		*stack = frsh;
		return (frsh);
	}

	while (curr)
	{
		if (!curr->next)
		{
			frsh->next = NULL;
			frsh->prev = curr;
			curr->next = frsh;
			break;
		}
		curr = curr->next;
	}

	return (frsh);
}

/**
 * _node_adds - adds a node to the start of stack
 * @stack: pointer to a pointer to a struct
 * @n: integer
 * Return: frsh node, if malloc fails, the function will return NULL
 */
stack_t *_node_adds(stack_t **stack, const int n)
{
	stack_t *frsh = malloc(sizeof(stack_t));

	if (!frsh)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(frsh);
		return (NULL);
	}
	frsh->n = n;

	frsh->next = *stack;
	frsh->prev = NULL;
	if (*stack)
		(*stack)->prev = frsh;

	*stack = frsh;

	return (frsh);
}

/**
 * stack_show - prints the contents of a stack_t stack
 * @stack: pointer to a pointer to a struct
 *
 * Return: number of elements of the list
 */
size_t stack_show(const stack_t *stack)
{
	size_t c = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		c++;
	}

	return (c);
}

/**
 * stack_empty - frees a dlistint_t linked list
 * @stack: pointer to a pointer to a struct
 *
 * Return: void
 */
void stack_empty(stack_t *stack)
{
	stack_t *curr = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (curr)
		{
			free(curr);
			curr = next;
			if (next)
				next = next->next;
		}
	}
}
