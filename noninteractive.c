#include "main.h"
/**
 * cignore - custom ignore spaces and newlines
 * @str: env vars
 * Rteurn: new string
 */
char *cignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}
/**
 * noninteractive - handles piping of commands into shell
 * @env: env vars
 */
void noninteractive(list_t *env)
{
	size_t i = 0, n = 0;
	int commandno = 0, exitstat = 0;
	char *command = NULL, *ncommand = NULL, **nline, **token;

	i = get_line(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	ncommand = command;
	command = cignore(command);
	nline = _strtok(command, "\n");
	if (ncommand != NULL)
		free(ncommand);
	n = 0;
	while (nline[n] != NULL)
	{
		commandno++;
		token = NULL;
		token = _strtok(nline[n], " ");
		exitstat = builtin(token, env, commandno, nline);
		if (exitstat)
		{
			n++;
			continue;
		}
		exitstat = _execve(token, env, commandno);
		n++;
	}
	freedoubleptr(nline);
	freelinkedlist(env);
	exit(exitstat);
}
