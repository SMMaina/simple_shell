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
