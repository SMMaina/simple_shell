#include "main.h"

/**
 * _which - gives cmd by adding it to path dir
 *  @str: first cmd typed by user
 *  @env: environment variable
 *  Return: compy of command
 */
char *_which(char *str, list_t *env)
{
	char *path, *cat = NULL, **tokens;
	int i = 0;

	path = getenvironment("PATH", env);
	tokens = cstrtok(path, ":");
	free(path);

	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(tokens[i]);
		cat = stringcat(cat, "/");
		cat = stringcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			freedoubleptr(tokens);
			return (cat);
		}
		free(cat);
		i++;
	}
	freedoubleptr(tokens);
	return (str);
}
