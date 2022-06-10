#include "main.h"
#include <stdio.h>

/**
 * get_path - function that searches for the path to execute
 * @env: arg passed to the path function
 *
 * Return: 0 upon success
 */
char **get_path(char **env)
{
	char *path_tok1;
	char *path_tok2;
	char *pathenv = NULL;
	char **argv = NULL;
	char *delim[2] = {"=:"};
	int a;

	a = 0;

	while (env[a])
	{
		path_tok1 = strtok(env[a], delim[0]);
		path_tok2 = strtok(NULL, delim[0]);

		if (strcmp(path_tok1, "PATH") == 0)
			break;
		a++;
	}

	pathenv = strtok(path_tok2, delim[0]);
	printf("%s", pathenv);
	a = 0;

	while (pathenv != NULL)
	{
		argv[a] = pathenv;
		pathenv = strtok(NULL, delim[1]);
		a++;
	}
	printf(" - %s\n", argv[a - 1]);
	argv[a] = NULL;
	return (argv);
}
