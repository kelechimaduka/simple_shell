#include "shell.h"
/**
 * _strchr - checks a char
 * @s: string
 * @c: the character
 * Return: success
 */
char *_strchr(char *s, char c)
{
	int len, x;

	len = str_len(s);
	for (x = 0; x < len; x++)
	{
		if (*(s + x) == c)
			return (s + x);
	}
	s = '\0';
	return (s);
}
/**
 * _strspn - gets length of string
 * @s: string
 * @accept: string
 * Return: success
 */
unsigned int _strspn(char *s, char *accept)
{
	int s_len, n, prod;
	s_len = str_len(s);
	n = 0;
	prod = 0;
	while (n < s_len)
	{
		if (_strchr(accept, *(s + n)))
			prod++, n++;
		else
			return (prod);
	}i
	return (prod);
}
/**
 * _strpbrk - searches a string
 * @s: string
 * @delims: bytes
 * Return: success
 */
char *_strpbrk(char *s, char *delims)
{
	char *tmp;

	tmp = delims;
	for (; *s != '\0'; s++)
	{
		while (*delims != '\0')
		{
			if (*s == *delims)
				return (s);
			delims++;
		}
		delims = tmp;
	}
	if (*s == '\0')
		return (0);

	return (s);
}
/**
 * str_tok - replicates token
 * @str: string
 * @dlim_: delimiter
 * @ptr_save: save pointer
 * Return: success
 */
char *str_tok(char *str, char *dlim_, char **ptr_save)
{
	char *tok;

	if (str == NULL)
	{
		if (*ptr_save == NULL)
			return (NULL);
		str = *ptr_save;
	}
	str += _strspn(str, dlim_);
	if (*str == '\0')
	{
		*ptr_save = NULL;
		return (NULL);
	}
	tok = str;
	str = _strpbrk(tok, dlim_);
	if (str == NULL)
		*ptr_save = NULL;
	else
	{
		*str = '\0';
		*ptr_save = str + 1;
	}
	return (tok);
}
