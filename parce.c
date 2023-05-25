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
 * Global variable: Flag, handles interrupt signals */
unsigned char sig_flag = 0;
/**
 * sighand - handles signals
 * @signal: signal
 */
static void sighand(int signal)
{
	if (signal == SIGINT && sig_flag == 0)
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
	char pipe_flag, *buffer, *cmd, *ptrsave, **tok;

