#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include <stdlib.h>

/**
 * _realloc - reasing a memory to a pointer
 * @ptr: pointer
 * @old_size: old size
 * @new_size: new size
 * Return: the new array with new size
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i = 0;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			p[i] = ((char *)ptr)[i];
		free(ptr);
	}
	if (old_size > new_size)
	{
		for (i = 0; i < new_size; i++)
			p[i] = ((char *)ptr)[i];
	}
	return (p);
}
