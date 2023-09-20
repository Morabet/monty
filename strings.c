#include "monty.h"

/**
 * is_valid_num - check if the string is a valid number.
 * @str: the pointer to string.
 * Return: return 0 if success , else 1
 */
int is_valid_num(char *str)
{
	int i = 0;

	if (!str)
		return (1);

	if (str[i] == '-')
		i++;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}

	return (0);
}
