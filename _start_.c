#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void err_file(char *argv);
void _err_usge(void);
int status = 0;

/**
 * main - entry point
 * @argc: argument count
 * @argv: array of pointers
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t chunk_l = 0;
	char *buff = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	universal.data_struct = 1;
	if (argc != 2)
		_err_usge();

	file = fopen(argv[1], "r");

	if (!file)
		err_file(argv[1]);

	while ((getline(&buff, &chunk_l, file)) != (-1))
	{
		if (status)
			break;
		if (*buff == '\n')
		{
			line_number++;
			continue;
		}
		str = strtok(buff, " \t\n");
		if (!str || *str == '#')
		{
			line_number++;
			continue;
		}
		universal.argument = strtok(NULL, " \t\n");
		_opcode_(&stack, str, line_number);
		line_number++;
	}
	free(buff);
	stack_empty(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * err_file - prints file error message and exits
 * @argv: array of pointers
 *
 * Desc: print message if  not possible to open the file
 * Return: nothing
 */
void err_file(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * _err_usge - prints usage message and exits
 * Desc: if user does not give any file or more than
 * one argument to your program
 *
 * Return: nothing
 */
void _err_usge(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
