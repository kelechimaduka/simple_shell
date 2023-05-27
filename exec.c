#include "shell.h"
/**
 * executee - executes a command
 * @argv: array of tokens
 * @environs: path
 * Return: Success
 */
void executee(char *argv[], env_t *environs)
{
	pid_t stat_1 = 0;
	char *absolutepath;
	char **Trace = environ;

	absolutepath = search_(argv[0], environs);
	if (!absolutepath)
	{
		perror("command not found\n");
		return;
	}

	switch (stat_1 = fork())
	{
		case -1:
			perror("fork failed\n");
			break;
		case 0:
			if (execve(absolutepath, argv, Trace) == -1)
				perror("execution failed\n");
			break;
		default:
			free(absolutepath);
			if (wait(NULL) == -1)
				perror("wait failed\n");
			break;
	}
}
