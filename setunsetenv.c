#include "main.h"
/**
 * findenvironment - find given env var in linked list
 * @env: env var linked list
 * @str: var name
 * Return: idx of node in linked list
 */
int findenvironment(list_t *env, char *str)
{
	int j = 0, index = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0')
			break;
		env = env->next;
		index++;
	}
	if (env == NULL)
		return (-1);
	return (index);
}
/**
 * _unsetenv - remove node in list
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success
 */
int _unsetenv(list_t **env, char **str)
{
	int index = 0, j = 0;

	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		freedoubleptr(str);
		return (-1);
	}
	index = findenvironment(*env, str[1]);
	freedoubleptr(str);
	if (index == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	j = deletenodeatindex(env, index);
	if (j == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}
/**
 * setenvironment - create vars
 * @env: linked list
 * @str: user's typed in cmd
 * Return: 0 on success
 */
int setenvironment(list_t **env, char **str)
{
	int index = 0, j = 0;
	char *concat;
	list_t *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		freedoubleptr(str);
		return (-1);
	}
	concat = _strdup(str[1]);
	concat = stringcat(concat, "=");
	concat = stringcat(concat, str[2]);
	index = findenvironment(*env, str[1]);
	if (index == -1)
	{
		addendnode(env, concat);
	}
	else
	{
		holder = *env;
		while (j < index)
		{
			holder = holder->next;
			j++;
		}
		free(holder->var);
		holder->var = _strdup(concat);
	}
	free(concat);
	freedoubleptr(str);
	return (0);
}
