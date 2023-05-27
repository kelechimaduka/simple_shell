#include "shell.h"
/**
 * builTin - checks cmd is abuiltin
 * @cmd: command
 * Return: On success or fail
 */
int (*builTin(char *cmd))()
{
	unsigned int x;
	builtin_cmds_t builds[] = {
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
		if (strn_cmp(builds[x].cmd_, cmd, str_len(builds[x].cmd_)) == 0)
			return (builds[x].function);
		x++;
	}
	return (NULL);
}
/**
 * exitTING - frees any remaining spaces
 * @environs: linked list
 * @buffer: buffer
 * @token: token
 * Return: Success
 */
int exitTING(char **token, env_t *environs, char *buffer)
{
	unsigned char exit_status;
	int y;

	for (y = 0; token[1] && token[1][y]; y++)
	{
		if (!is_digit(token[1][y]))
		{
			printTing("numeric argument required, exiting\n");
			break;
		}
	}
	exit_status = token[1] && y >= str_len(token[1]) ? _atoi(token[1]) : 0;
	if (environs && buffer && token)
	{
		freelist(environs);
		environs = NULL;
		free(token);
		token = NULL;
	}
	exit(exit_status);
	return (-1);
}
/**
 * _env - prints current environment
 * @token: token
 * @environment: list environment
 * Return: 0 or -1
 */
int _env(char **token, env_t *environment)
{
	char **en = environ;

	if (token[1])
		printTing("No arguments are necessary\n");
	if (!en || !environ)
		return (-1);
	for ( ; *en; en++)
	{
		write(STDOUT_FILENO, *en, str_len(*en));
		write(STDOUT_FILENO, "\n", 1);
	}
	environment++;
	return (0);
}
/**
 * cdD - change working directory
 * @token: list
 * Return: Success
 */
int cdD(char **token)
{
	char *targ;
	char pwd[BUFSIZE];
	char *home;

	home = get_env("HOME");
	if (token[1])
	{
		if (token[1][0] == '~' && !token[1][1])
			targ = home;
		else if (token[1][0] == '-' && !token[1][1])
			targ = get_env("OLDPWD");
		else
			targ = token[1];
	}
	else
		targ = home;
	if (targ == home)
		chdir(targ);
	else if (access(targ, F_OK | R_OK) == 0)
		chdir(targ);
	else
		printTing("Could not find dirctory\n");
	set_env("OLDPWD", get_env("PWD"), 1);
	set_env("PWD", getcwd(pwd, sizeof(pwd)), 1);
	return (0);
}
