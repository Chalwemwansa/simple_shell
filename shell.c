#include "main.h"
/**
 * cop - copies strings
 *
 * @tocken: variable used
 * @str: parameter passed
 * @new: parameeter passed
 * Return: character array
 */
char *cop(char *str, char *new, char *tocken)
{
	char *path = "/bin/";
	int iter = 0, iter1 = 0;

	tocken = strtok(str, " ");
	while (path[iter] != '\0')
	{
		new[iter] = path[iter];
		iter++;
	}
	while (tocken[iter1])
	{
		new[iter] = tocken[iter1];
		iter++;
		iter1++;
	}
	return (new);
}
/**
 * handle - handles output and reading from screen
 *
 * @str2: variable used in the code
 * @str1: variable used in the code
 * @arg:variable used in the code
 * @new1: variable used in the code
 * Return: nothing
 */
void handle(char **str2, char *str1[], char *arg[], char **new1)
{
	int ch, i = 0;
	size_t buffsize;
	ssize_t get = 0;
	char *tocken = NULL, *str = *str2, *new = *new1;

	write(STDOUT_FILENO, "#cisfun$ ", 11);
	get = getline(&str, &buffsize, stdin);
	if (get == -1)
	{
		free(*new1);
		free(*str2);
		perror(arg[0]);
		exit(EXIT_FAILURE);
	}
	ch = 0;
	while (str[ch])
	{
		if (str[ch] == '\n')
			str[ch] = '\0';
		ch = ch + 1;
	}
	if (check(str) == -1)
	{
		free(*new1);
		free(*str2);
		exit(0);
	}
	str1[i] = cop(str, new, tocken);
	while (str1[i++] != NULL)
		str1[i] = strtok(NULL, " ");

}
/**
 * mal - mallocs a string
 *
 * @new:variable passed
 * @arg: list of arguments to the function
 * Return: nothing
 */
void mal(char **new, char *arg[])
{
	*new = malloc(sizeof(char) * 100);
	if (*new == NULL)
	{
		perror(arg[0]);
		exit(90);
	}
}
/**
 * checkfile - checks if the file exists
 *
 * @arg: arguments that were passed to main
 * @str1: new string
 * Return: an int
 */
int checkfile(char **arg, char **str1)
{
	pid_t dirt = 0;
	int y;

	dirt = open(str1[0], O_RDONLY);
	y = (int)dirt;
	if (dirt == -1)
		perror(arg[0]);
	else
		close(dirt);
	return (y);
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
	int status, exec = 0;
	char *str = NULL, *str1[100] = {NULL}, *new = NULL;

	for (;;)
	{
		mal(&new, arg);
		handle(&str, str1, arg, &new);
		if (checkfile(arg, str1) != -1)
		{
			pid = fork();
			if (pid == -1)
			{
				free(new);
				free(str);
				perror(arg[0]);
				exit(EXIT_FAILURE);
			}
		}
		if (pid == 0)
		{
			exec = execve(str1[0], str1, argv);
			if (exec == -1)
			{
				free(new);
				free(str);
				perror(arg[0]);
			}
		}
		else
		{
			wait(&status);
			free(str);
			free(new);
		}
	}
}
