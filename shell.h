#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024
extern char **Envi;
/**
 * struct envi_type - linked list
 * @str: path
 * @len: length
 * @next: next node
 */
typedef struct envi_type
{
	char *str;
	unsigned int len;
	struct envi_type *next;
}
env_t;

/**
 * struct builtin_cmd - struct for builtin commands
 * @cmd_: commands
 * @function: function
 */
typedef struct builtin_cmd
{
	char *cmd_;
	int (*function)();
}
builtin_cmds_t;

int (*builTin(char *cmd))();
int exitTING(char **token, env_t *environ, char *buffer);
int _env(char **token, env_t *environment);
int cdD(char **token);
int set_user(char **token);
int stren(void);
int past(void);
int barbie(void);
env_t *list_path(void);
env_t *envi_L_list(void);
char *search_(char *cmd, env_t *environ);
char *get_env(const char *nom);
int set_env(const char *nom, const char *value, int overwrite);
env_t *addnode(env_t **head, char *str, unsigned int len);
void freelist(env_t *head);
void executee(char *argv[], env_t *environ);
void *re_alloc(char *ptr, unsigned int old, unsigned int new_size);
void mem_set(char *str, int fill, int x);
void mem_cpy(char *dest, char *src, unsigned int bytes);
char *get_line(int file);
char **parse_(char *str, char *dlim_);
void reader(void);
char *str_tok(char *str, char *dlim_, char **ptr_save);
int str_len(char *s);
int strn_cmp(char *s1, char *s2, size_t bytes);
char *str_up(char *src);
char *strcalloc(char *dest, char *src);
int _atoi(char *s);
int is_digit(int a);
unsigned int count_(char *str);
void printTing(const char *str);
int strlen_const(const char *s);
size_t print_list(const env_t *b);

#endif
