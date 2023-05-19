#include "shell.h"
/**
 * builTin - checks cmd is abuiltin
 * @cmd: command
 * Return: On success or fail
 */
int (builTin(char *cmd))();
{
	unsigned int x;
	builtin_c builds[] = {
		{"alias", stren},
		{"cd", cdD},
		{"env", _env},
		{"exit", exitTING},
		{"history", past},
		{"setenv", set_env},
		{"bowie", barbie},
		{NULL, NULL}
	};

	x = 0;
	while (*builds[x].function != NULL)
	{
		if (
