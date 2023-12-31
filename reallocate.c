#include "main.h"

/**
 * *_memset - fills a memory address with a constant byte.
 *@s: the pointer to the memory area.
 *@b: the byte to fill address space with.
 *@n: the amount of bytes to be filled.
 *Return: a pointer to the memory location.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a double array of characters.
 * @pp: a double array of characters.
 * Return: void.
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - used to reallocate a block of memory.
 * @ptr: a pointer to the previous block which was malloced.
 * @old_size: previous block byte size..
 * @new_size: new block byte size.
 *
 * Return: pointer to adjusted block or same block..
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
