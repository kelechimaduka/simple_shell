#include "shell.h"
/**
 * get_line - gets line to place in puffer
 * @file: file
 * Return: Success
 */
char *get_line(int file)
{
	unsigned int i, index;
	char *buffer;
	static unsigned int buffer_size = BUFSIZE;

	buffer = malloc(sizeof(char) * buffer_size);
	if (buffer == NULL)
	{
		perror("malloc for buffer failed\n");
		return (NULL);
	}
	index = 0;
	mem_set(buffer, '\0', buffer_siz);
	while ((i = read(file, buffer + index, buffer_size - index)) > 0)
	{
		if (i < (buffer_size - index))
			return (buffer);
		buffer_size *= 2;
		re_alloc(buffer, buffer_size, buffer_size / 2);
		if (buffer == NULL)
		{
			perror("realloc failed\n");
			return (NULL);
		}
		index += i;
	}
	if (i == 0)
		mem_cpy(buffer, "exit", 5);
	return (buffer);
}
/**
 * parse_ - parse string to token
 * @str: string
 * @dlim_: delimi
 * Return: success
 */
char **parse_(char *str, char *dlim_)
{
	char *tok, *ptrsave, **tok_d;
	unsigned int i, j;

	j = count_(str);
	tok_d = malloc((j + 1) * sizeof(char *));
	if (!tok_d)
	{
		perror("malloc failed\n");
		return (NULL);
	}
	tok_d[0] = tok = str_tok(str, dlim_, &ptrsave);
	for (i = 1; tok, i++)
		tok_d[i] = tok = str_tok(NULL, dlim_, &ptrsave);
	return (tok_d);
}
/**
 * sighand - handles signals
 * @sigl: signal
 */
static void sighand(int sigl)
{
	if (sigl == SIGINT && sig_flag == 0)
		printTing("\nAnd baby says: ");
	else if (sig_flag != 0)
		printTing("\n");
}
/**
 * main - entry
 * Return: Success
 */
int main(void)
{
	char pipe_flag, *buffer, *cmd_, *ptrsave, **tok;
	env_t environ;
	struct stat stat_buff;

	if (signal(SIGINT, sighand) == SIG_ERR)
		perror("signal error\n");
	if (fstat(STDIN_FILENO, &stat_buff) == -1)
		perror("fstat error\n"), exit(98);
	pipe_flag = (stat_buff.st_mode & S_IFMT) == S_IFCHR ? 0 : 1;
	environ = list_path();
	if (environ == NULL)
		return (-1);
	ptrsave = NULL;
	while (1)
	{
		sig_flag = 0;
		if (pipe_flag == 0)
			printTing("And baby says: ");
		buffer = get_line(STDIN_FILENO);
		if (!buffer)
			break;
		cmd_ = str_tok(buffer, "\n;", &ptrsave);
		while (cmd_)
		{
			tok = parse_(cmd_, "\t ");
			if (!tok)
				break;
			if (builTin(tok[0]))
				builTin(tok[0])(tok, environ, cmd_);
			else
				sig_flag = 1, executee(tok, environ);
			free(tok);
			cmd_ = str_tok(NULL, "\n;", &ptrsave);
		}
		free(buffer);
	}
	return (0);
}
