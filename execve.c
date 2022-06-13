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
int executeve(char **string, list_t *env, int n)
{
	char *hold;
	int status = 0, t = 0;
	pid_t pid;

	if (access(str[0], F_OK) == 0)
	{
		hold = str[0];
		t = 1;
	}
	else
		hold = _which(str[0], env);
	if (access(hold, X_OK) != 0)
	{
		notfound(str[0], n, env);
		freedoubleptr(str);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(hold, str, NULL) == -1)
			{
				notfound(str[0], n, env);
				exitc(str, env);
			}

		}
		else
		{
			wait(&status);
			freedoubleptr(str);
			if (t == 0)
				free(hold);
		}
	}
	return (0);
}
