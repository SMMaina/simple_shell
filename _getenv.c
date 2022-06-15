#include "main.h"

/**
 * _getenv - prints the current environment
 * @env: environment
 * Return: the current environment
 */

char *_getenv(char *env)
{
	int i, n;
	char *temp, *res;

	i = 0;
	n = 0;

	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], env) == 0)
		{
			temp = environ[i];
		}
		i++;
	}

	while (temp[n] != '\0')
	{
		if (_strcmp(temp, env) == 0)
		{
			res = _strstr(temp, "/");
		}
		n++;
	}
	return (res);
}
