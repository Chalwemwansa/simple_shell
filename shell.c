#include "main.h"

/**
 * shell - a shell by William and Chalwe
 *
 * @arg: list of arguments to the function
 * @argv: list of environment variables
 * Return: nothing
 */

void shell(char *arg[], char *argv[])
{
	pid_t pid;
	int status, ch;
	ssize_t get = 0;
	size_t buffsize;
	char *str = NULL, *str1[] = {NULL, NULL};

	for (;;)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 12);
		get = getline(&str, &buffsize, stdin);
		if (get == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		ch = 0;
		while (str[ch++])
		{
			if (str[ch] == '\n')
				str[ch] = '\0';
		}
		str1[0] = str;
		pid = fork();
		if (pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(str1[0], str1, argv) == -1)
			{
				perror(arg[0]);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
