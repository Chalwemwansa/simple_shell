#include "main.h"

/**
 * bfree - frees a pointer and points it to NULL.
 * @ptr: the address of the pointer to be freed.
 *
 * Return: returns 1 if succesfully freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
