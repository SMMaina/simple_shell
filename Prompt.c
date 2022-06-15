#include "main.h"

/**
 * control - overlooks the ctrl-c input and primts the prompt again
 * @n: takes an int from signal
 */
void control(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/**
 * builtin- function that handles the respective builtins(exit, env, cd)
 * @tok: what the user has input
 * @env: environment variable
 * @n: takes the nthcomand typed by uer to write the err message
 * @command: command to free
 * Return:1 when acted on builtin and 0 if not
 */
int builtin(char **tok, list_t *env, int n, char **command)
{
	int i = 0;

	if (stringcmp(tok[0], "exit") == 0)
	{
		i = __exit(tok, env, n, command);
	}
	else if (stringcmp(tok[0], "env") == 0)
	{
		environment(tok, env);
		i = 1;
	}
	else if (stringcmp(tok[0], "unsetenv") == 0)
	{
		_unsetenv(&env, tok);
		i = 1;
	}
	return (i);
}

/**
 * ignorespace - returns a string without spaces in front
 * @string: said string
 * Return: new one
 */
char *ignorespace(char *string)
{
	while (*string == ' ')
		string++;
	return (string);
}

/**
 * controld - exits the program
 * @n: charas read through getline
 * @command: user's comand input
 * @env: env variable linked list
 */
void controld(int n, char *command, list_t *env)
{
	if (n == 0)
	{
		free(command);
		freelinkedlist(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}
/**
 * Prompt - displays repeatedly user's command and executes
 * @en: environment variabes
 * Return: 0 upon success
 */
int Prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int commandno = 0, exitstat = 0;
	char *command, *ncommand, **token;

	env = envlinkedlist(en);
	do {
		commandno++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		else
			noninteractive(env);
		signal(SIGINT, control);
		command = NULL, i = 0;
		i = get_line(&command);
		controld(i, command, env);
		ncommand = command;
		command = ignorespace(command);
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		if (command[0] == '\0')
		{
			free(ncommand);
			continue;
		}
		token = NULL;
		token = _strtok(command, " ");
		if (ncommand != NULL)
		{
			free(ncommand);
		}
		exitstat = builtin(token, env, commandno, NULL);
		if (exitstat)
			continue;
		exitstat = _execve(token, env, commandno);
	} while (1);
	return (exitstat);
}
