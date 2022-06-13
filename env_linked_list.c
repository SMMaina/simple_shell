#include "main.h"
/**
 * env_linked_list - creates a linked list of env var
 * @env: env vars
 * Return: linked list
 */
list_t *env_linked_lit(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_endnode(&head, env[i]);
		i++;
	}
	return (head);
}
/**
 * environment - prints env vars
 * @str: user command in shell
 * @env: env vars
 * Return: 0 upon succes
 */
int environment(char **str, list_t *env)
{
	freedoubleptr(str);
	printlist(env);
	return (0);
}
