#include "main.h"
/**
 * handle - handles output and reading from screen
 *
 * @str: variable used in the code
 * @str1: variable used in the code
 * @arg:variable used in the code
 * Return: nothing
 */
void handle(char *str, char *str1[], char *arg[])
{
	int ch, i = 0;
	size_t buffsize;
	ssize_t get;

	write(STDOUT_FILENO, "#cisfun$", 11);
	get = getline(&str, &buffsize, stdin);
	if (get == -1)
	{
		free(str);
		perror(arg[0]);
		exit(EXIT_FAILURE);
	}
	check(str);
	ch = 0;
	while (str[ch])
	{
		if (str[ch] == '\n')
			str[ch] = '\0';
		ch = ch + 1;
	}
	str1[i] = strtok(str, " ");
	while (str1[i++] != NULL)
		str1[i] = strtok(NULL, " ");

}
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
	int status;
	char *str = NULL, *str1[100] = {NULL};

	for (;;)
	{
		handle(str, str1, arg);
		pid = fork();
		if (pid == -1)
		{
			free(str);
			perror(arg[0]);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(str1[0], str1, argv) == -1)
			{
				free(str);
				perror(arg[0]);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
