#include "main.h"
/**
 * check - checks if exit
 *
 * @str: string to be checked
 * Return: nothing
 */
void check(char *str)
{
	int i = 0;
	char ex[] = "exit";
	while (str[i] != '\0')
	{
		if (ex[i] != str[i])
			break;
		if (i == 3 && (ex[i] == str[i]))
		{
			exit(0);
		}
		i++;
	}
}
