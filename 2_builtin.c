#include "shell.h"
/**
 * set_user - sets environmental variables as user defines
 * @token: teken
 * Return: 0 on success, -1 on failure
 */

int set_user(char **token)
{
	int i, wc, stats;
	char *pass, *val, *ptrs;

	for (i = 0, wc = 1; token[1][i]; i++)
		if (token[1][i] == '=')
			wc++;
	for (i = 0; token[i]; i++)
		;
	if (!token[1] || i == 0 || wc != 2)
	{
		printTing("setenv: Usage: setenv KEY=VALUE\n");
		return (-1);
	}
	pass = str_tok(token[1], "=", &ptrs);
	val = str_tok(NULL, "=", &ptrs);
	stats = set_env(pass, val, 0);
	if (stats == 0)
		return (stats);
	return (-1);
}
/**
 * stren - sets aliases
 * Return: Success
 */
int stren(void)
{
	printTing("alias: usage: alias [-p] [name[=value] ... ]\n");
	printTing("\tSet or view aliases.\n\tSet with name=value\n");
	printTing("\tView list of aliases with no arguments or -p\n");
	return (0);
}
/**
 * past - prints history
 * Return: 0 for success
 */
int past(void)
{
	printTing("history: usage: history [-c]\n");
	printTing("\tView the history of commands\n ");
	printTing("\t'history -c' clears the history\n");
	return (0);
}
/**
 * barbie - displays picture of barbie
 * Return: success
 */
int barbie(void)
{
	int textfile, total, readstats;
	size_t letters = 7483;
	char *nameoffile = "barbie.txt";
	char buffer[BUFSIZE];

	if (nameoffile == NULL)
		return (0);
	textfile = open(nameoffile, O_RDONLY);
	if (textfile == -1)
		return (0);
	total = 0;
	readstats = 1;
	while (letters > BUFSIZE && readstats != 0)
	{
		readstats = read(textfile, buffer, BUFSIZE);
		write(STDOUT_FILENO, buffer, readstats);
		total += readstats;
		letters -= BUFSIZE;
	}
	readstats = read(textfile, buffer, letters);
	write(STDOUT_FILENO, buffer, readstats);
	total += readstats;
	close(textfile);
	return (1947);
}
