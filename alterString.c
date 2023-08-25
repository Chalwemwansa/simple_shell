#include "main.h"

/**
 * _strlen - gets length of a string.
 * @s: string passed as parameter.
 *
 * Return: the length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings.
 * @s1: first string being compared
 * @s2: second string being compared.
 *
 * Return: zero if s1 equals s2, positive if s1 > s2 and negative if s1 < s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - function checks if argument starts with haystack.
 * @haystack: string being checked in argument.
 * @needle: substring to be found.
 *
 * Return: NULL or the address of the next charater of haystack.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - joins two strings together.
 * @dest: the destination string.
 * @src: the source string.
 *
 * Return: a pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
