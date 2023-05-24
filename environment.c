#include "shell.h"
/**
 * list_path - creates linked list
 * Return: Success
 */
env *list_path(void)
{
	unsigned int i, j, k;
	char *envs;
	char buffer[BUFSIZE];
	env *E_p;

	E_p = NULL;
	i = j = k = 0;
	envs = get_env("PATH");
	while (*envs)
	{
		buffer[j++] = *envs;
		k++;
		if (*envs == ':')
		{
			k--;
			buffer[j - 1] = '/';
			buffer[j] = '\0';
			addnode(&E_p, buffer, k);
			k = j = 0;
		}
		envs++;
	}
	return (E_p);
}
/**
 * envi_L_list - creates linked list from PATH
 * Return: Success
 */
env *envi_L_list(void)
{
	int i, j;
	char **envs;
	env *E_p;

	E_p = NULL;
	i = j = 0;
	envs = Envi;
	while (envs[i])
	{
		addnode(&E_p, envs[i], (unsigned int)str_len(envs[i]));
		i++;
	}
	return (E_p);
}
/**
 * search_ - searches for command
 * @cmd: comand
 * @environ: path to search through
 * Return: Success
 */
char *search_(char *cmd, env *environ)
{
	int stats;
	char *absolutepath;
	env *E_p;

	E_p = environ;
	if (E_p == NULL || cmd == NULL)
		return (NULL);
	if ((strn_cmp(cmd, "/", 1) == 0
				|| strn_cmp(cmd, "./", 2) == 0)
			&& access(cmd, F_OK | X_OK) == 0)
	{
		absolutepath = str_up(cmd);
		return (absolutepath);
	}
	while (E_p != NULL)
	{
		absolutepath = str_up(E_p->str);
		if (absolutepath == NULL)
			return (NULL);
		absolutepath = strcalloc(absolutepath, cmd);
		if (absolutepath == NULL)
			return (NULL);
		stats = access(absolutepath, F_OK | X_OK);
		if (stats == 0)
			return (absolutepath);
		free(absolutepath);
		E_p = E_p->next;
	}
	return (NULL);
}
