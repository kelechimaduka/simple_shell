#include "shell.h"
/**
 * count_ - counts words
 * @str: string
 * Return: success
 */
unsigned int count_(char *str)
{
	unsigned int x, y, flag;
	char *dlim_ = "\n \t";

	for (x = 0, y = 1, flag = 0; str[x]; x++)
	{
		if (flag == 0 &&
				(str[x] == dlim_[0]
				|| str[x] == dlim_[1]
				|| str[x] == dlim_[2])
				&& str[x + 1] != dlim_[0]
				&& str[x + 1] != dlim_[1]
				&& str[x + 1] != dlim_[2])
			flag = 1, y++;
		else
			flag = 0;
	}
	return (y);
}
/**
 * strlen_const - for constant strings
 * @s: string
 * Return: Success
 */
int strlen_const(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
 * printTing - prints string
 * @str: string
 */
void printTing(const char *str)
{
	int j;

	j = strlen_const(str);
	write(STDOUT_FILENO, str, j);
}
/**
 * is_digit - checks if digit
 * @a: char
 * Return: success
 */
int is_digit(int a)
{
	return ((a >= '0' && a <= '9') ? 1 : 0);
}
