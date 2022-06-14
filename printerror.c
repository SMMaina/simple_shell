#include "main.h"
/**
 * notfound - write error
 * @str: user's typed command
 * @cn: nth user's typed command
 * @env: env vars
 */
void notfound(char *str, int cn, list_t *env)
{
	int count = 0;
	char *shell, *n;

	shell = getenvironment("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	n = inttostring(cn);
	count = 0;
	while (n[count] != '\0')
		count++;
	write(STDOUT_FILENO, n, count);
	free(n);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}
/**
 * cantcdto - write error
 * @str: user typed arg
 * @cn: nth user's typed comand
 * @env: env vars
 */
void cantcdto(char *str, int cn, list_t *env)
{
	int count = 0;
	char *shell, *n;

	shell = getenvironment("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	n = inttostring(cn);
	count = 0;
	while (n[count] != '\0')
		count++;
	write(STDOUT_FILENO, n, count);
	free(n);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}
/**
 * illegalnumber - write error
 * @str: user's typed arg
 * @cn: nth user typed command
 * @env: env vars
 */
void illegalnumber(char *str, int cn, list_t *env)
{
	int count = 0;
	char *shell = NULL, *n = NULL;

	shell = getenvironment("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	n = inttostring(cn);
	count = 0;
	while (n[count] != '\0')
		count++;
	write(STDOUT_FILENO, n, count);
	free(n);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}
