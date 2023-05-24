#include "shell.h"
/**
 * re_alloc - relocates memory
 * @ptr: pointer
 * @old: old size
 * @ne_size: new size
 * Return: success
 */
void *re_alloc(char *ptr, unsigned int old, unsigned int new_size)
{
	char *tmp, *store;
	unsigned int i;

	if (ptr == NULL)
	{
		store = malloc(new_size);
		if (store == NULL)
			return (NULL);
		return (store);
	}
	if (new_size == old)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old)
	{
		store = malloc(new_size * sizeof(char));
		tmp = ptr;

		mem_set(store, '\0', new_size);
		for (i = 0; i < old; i++)
			store[i] = tmp[i];
		free(ptr);
		return (store);
	}
	return (ptr);
}
/**
 * mem_set - fills a string with numbers
 * @str: string
 * @fill: char
 * @x: number of char
 */
void mem_set(char *str, int fill, int x)
{
	int i;

	for (i = 0; i < x; i++)
		str[i] = fill;
}
/**
 * mem_cpy - copies some part of the string
 * @dest: destination
 * @src: source
 * @bytes: number of bytes
 */
void mem_cpy(char *dest, char *src, unsigned int bytes)
{
	unsigned int i;

	for (i = 0; i < bytes; i++)
		dest[i] = src[i];
}
