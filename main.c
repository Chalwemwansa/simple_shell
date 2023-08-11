#include "main.h"
/**
 * main - calls other functions
 *
 * @argv: list of environment variables
 * Return: an int 0 on succes and another number on failure
 * @arg: list of arguments passed as arguments
 * @argc: the number of arguments passed t the function main
 */
int main(int argc, char *arg[], char *argv[])
{
	if (argc == 1)
		shell(arg, argv);
	return (0);
}
