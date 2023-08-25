#include "main.h"

/**
 *_eputs - prints the string to be input.
 * @str: string to be printed.
 *
 * Return: void, doesn't return anything.
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes characters to standard error.
 * @c: specifies character to be printed.
 *
 * Return: returns  1 on success and -1 on failure.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes a given character to specified fd.
 * @c: character to be printed.
 * @fd: file descriptor to write to.
 *
 * Return: returns 1 on success and -1 on error.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - gets length of input string.
 * @str: string to be checked.
 * @fd: file descriptor being written to.
 *
 * Return: number of characters that were in string.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
