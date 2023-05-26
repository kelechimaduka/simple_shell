#include "shell.h"
/**
 * addnode - adds new node
 * @head: start
 * @str: string
 * @len: length of string
 * Return: Success
 */
env_t *addnode(env_t **head, char *str, unsigned int len)
{
	env_t *new, *ju;
	char *str2;

	if (str == NULL)
		return (NULL);
	str2 = str_up(str);
	if (str2 == NULL)
		return (NULL);
	new = malloc(sizeof(env));
	if (new == NULL)
		return (NULL);
	new->str = str2;
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	ju = *head;
	while (ju->next != NULL)
		ju = ju->next;
	ju->next = new;
	return (*head);
}
/**
 * freelist - frees list
 * @head: start
 */
void freelist(env_t *head)
{
	if (head == NULL)
		return;
	freelist(head->next);
	free(head->str);
	free(head);
}
