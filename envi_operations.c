#include "shell.h"
/**
 * get_env - gets the environment from key
 * @nom: string to search environment
 * Return: success
 */
char *get_env(const char *nom)
{
	int i, j, k;
	char **envs, **Envi, *temp;

	if (!nom)
		return (NULL);
	envs = Envi;
	for (i = 0; envs[i]; i++)
	{
		for (k = 0; envs[i][k] != '='; k++)
			;
		k++;
		temp = malloc((k) * sizeof(char));
		mem_cpy(temp, envs[i], k - 1);
		temp[k - 1] = '\0';
		if (strn_cmp((char *)nom, temp, str_len(temp)) == 0)
		{
			free(temp);
			temp = NULL;
			for (j = 0; envs[i][j]; j++)
			{
				if (envs[i][j] == '=')
				{
					temp = &envs[i][j + 1];
					break;
				}
			}
			return (temp);
		}
		free(temp);
		temp = NULL;
	}
	return (NULL);
}
/**
 * del_env - removes a value from the enviromnent
 * @nom: name of key
 * Return: Success
 */
int del_env(const char *nom)
{
	return (unsetenv(nom));
}
/**
 * set_env - add a value to environment
 * @nom: name of key
 * @value: value of key
 * @overwrite: flag
 * Return: Success
 */
int set_env(const char *nom, const char *value, int overwrite)
{
	return (setenv(nom, value, overwrite));
}
