#include "main.h"
/**
 * bin - checks if /bin/ is already included
 *
 * @tocken: the tocken to be checked
 * Return: 0 if /bin/ is not included
 */
int bin(char *tocken)
{
	int i = 0;
	char *bin = "/bin/";

	while (i <= 4)
	{
		if (bin[i] != tocken[i])
			return (0);
		i++;
	}
	return (1);
}
