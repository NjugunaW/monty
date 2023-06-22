#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./monty.h"

/**
 * _opcode_ - function in charge of running builtins
 * @stack: pointer to a pointer to a struct
 * @str: string
 * @line_number: unsigned integer
 * Return: nothing
 */
void _opcode_(stack_t **stack, char *str, unsigned int line_number)
{
	int x = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		universal.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		universal.data_struct = 0;
		return;
	}

	while (op[x]._opcode_)
	{
		if (strcmp(op[x]._opcode_, str) == 0)
		{
			op[x].f(stack, line_number);
			return;
		}
		x++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
}
