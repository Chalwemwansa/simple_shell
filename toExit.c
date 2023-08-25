#include "main.h"

/**
 * *_strncpy - copies one strings content to anothers.
 *@dest: destination string being copied to.
 *@src: the string to be copied from.
 *@n: the total number of characters to be copied from the src string.
 *Return: a pointer to the new string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *_strncat - adds two strings to each other.
 *@dest: the string to be added to.
 *@src: the string to copy from.
 *@n: the number of characters in src.
 *Return: the string consisting of the two strings.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - searches for a character in a string.
 *@s: string being checked.
 *@c: character to search for.
 *Return: a pointer to the location where character is, else NULL.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
