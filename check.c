#include "main.h"

/**
 * check - checks if exit
 *
 * @str: gives string to be checked
 * Return: nothing
 */

int check(char *str)
{
	int i = 0;
	char ex[] = "exit";

	while (str[i] != '\0')
	{
		if (ex[i] != str[i])
			break;
		if (i == 3 && (ex[i] == str[i]))
			return (-1);
		i++;
	}
	return (0);
}
