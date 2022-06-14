#include "main.h"
/**
 * cstrdup - custom string duplication
 * @str: string to duplicate
 * @ex: no of bytes to exclude
 * Return: string
 */
char *cstrdup(char *str, int ex)
{
	char *dupstr;
	int i, length = 0;

	if (str == NULL)
		return (NULL);
	while (*(str + length))
		length++;
	length++;

	dupstr = malloc(sizeof(char) * (length - ex));
	if (dupstr == NULL)
		return (NULL);

	i = 0;
	while (i < (length - ex))
	{
		*(dupstr + i) = *(str + ex + i);
		i++;
	}
	return (dupstr);
}

/**
 * getenv - finds and returns a copy of requested environment
 * @str: string to store in
 * @env: entire env variables
 * Return: copy of requested env variable
 */
char *getenvironment(char *str, list_t *env)
{
	int j = 0, ex = 0;

	while (env != NULL)
	{
		j = 0;

		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}
	while (str[ex] != '\0')
		ex++;
	ex++;
	return (cstrdup(env->var, ex));
}
