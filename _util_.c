#include <ctype.h>
#include "monty.h"

/**
 * digit_checker - checks if theres a digit in a string
 * @string: string
 *
 * Return: 1 if success, 0 if not
 */
int digit_checker(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
/**
 * num_checker - checks if a string is a number
 * @str: string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int num_checker(char *str)
{
	int n;

	if (!str)
		return (0);

	for (n = 0; str[n]; n++)
		if (n < '0' || n > '9')
			return (0);

	return (1);
}
