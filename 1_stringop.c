#include "shell.h"
/**
 * str_len - string length
 * @s: string concerned
 * Return: Success
 */
int str_len(char *s)
{
	int x;

	for (x = 0; *s; s++, x++)
		;
	return (x);
}
/**
 * strn_cmp - compares two strings
 * @s1: first string
 * @s2: second string
 * @bytes: bytes
 * Return: Success
 */
int strn_cmp(char *s1, char *s2, size_t bytes)
{
	unsigned int x;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (x = 0; s1[x] && s2[x] && s2[x] == s1[x] && x < bytes - 1; x++)
		;
	return (s2[x] - s1[x]);
}
/**
 * str_up - duplicates string
 * @src: Source
 * Return: Success
 */
char *str_up(char *src)
{
	int i, j;
	char *dest;

	if (src == NULL)
		return (NULL);
	j = str_len(src);
	if (j < 0)
		return (NULL);
	j++;
	dest = malloc((j) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < j; i++)
		dest[i] = src[i];
	dest[i - 1] = '\0';
	return (dest);
}
/**
 * strcalloc - concatenates 2 strings and relocates them
 * @dest: destination
 * @src: source
 * Return: Success
 */
char *strcalloc(char *dest, char *src)
{
	unsigned int dest_i, src_i, i;

	dest_i = str_len(dest);
	src_i = str_len(src);
	dest = re_alloc(dest, dest_i, dest_i + src_i + 1);
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < src_i; i++)
	{
		dest[i + dest_i] = src[i];
	}
	dest[i + dest_i] = '\0';
	return (dest);
}
/**
 * _atoi - converts string to integer
 * @s: string
 * Return: Success
 */
int _atoi(char *s)
{
	int x, sign, prod;

	for (x = prod = 0, sign = 1; s[x]; x++)
	{
		if (s[x] == '-')
			sign *= -1;
		if (s[x] >= '0' && s[x] <= '9')
			prod = 10 * prod - (s[x] - '0');
		if (prod < 0 && (s[x] < '0' || s[x] > '9'))
			break;
	}
	if (sign > 0)
		prod *= -1;
	return (prod);
}
