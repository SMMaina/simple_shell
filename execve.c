#include "main.h"
/**
 * exitc - frees user command
 * @str: user's typed command
 * @env: input linked list of env
 */
void exitc(char **str, list_t *env)
{
	freedoubleptr(str);
	freelinkedlist(env);
	_exit(0);
}
/**
 * executeve - execute command typed into shell
 * @string: command user typed
 * @env: environmental variable
 * @n: nth user command
 * Return: 0 on success
 */
int _execve(char **string, list_t *env, int n)
{
	char *hold;
	int status = 0, t = 0;
	pid_t pid;

	if (access(string[0], F_OK) == 0)
	{
		hold = string[0];
		t = 1;
	}
	else
		hold = _which(string[0], env);
	if (access(hold, X_OK) != 0)
	{
		notfound(string[0], n, env);
		freedoubleptr(string);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(hold, string, NULL) == -1)
			{
				notfound(string[0], n, env);
				exitc(string, env);
			}

		}
		else
		{
			wait(&status);
			freedoubleptr(string);
			if (t == 0)
				free(hold);
		}
	}
	return (0);
}
