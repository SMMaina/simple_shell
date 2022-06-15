#include "main.h"

/**
 * exit_shell - exits the shell
 * @args: arguments
 * @line: line buffer of user input
 * @env: a NULL terminated array of strings
 * Return: void
 */

void exit_shell(char **args, char *line, char **env)
{
	free(args);
	free(line);
	(void)env;
	exit(0);
}


/**
 * env_shell - prints the current environment
 * @args: arguments
 * @line: line buffer of user input
 * @env: a NULL terminated array of strings
 */

void env_shell(char **args, char *line, char **env)
{
	int size, i;

	i = 0;

	while (env[i] != NULL)
	{
		size = _strlen(env[i]);
		write(1, env[i], size);
		write(1, "\n", 1);
		i++;
	}
	(void)args;
	(void)line;
}
