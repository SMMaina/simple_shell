#include "main.h"
/**
 * catoi - converts string to int
 * @str: string
 * Return: nteger upon success and -1 if otherwise
 */
int catoi(char *str)
{
	int i = 0;
	unsigned int n = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	return (n);
}
/**
 * _exit - frees the user input and then exit the main program
 * @str: user command
 * @env: environment varibale to free
 * @n: bring the nth command of user
 * @command: bring command to free
 * return: 0 upon success 2 upon failure
 */
int __exit(char **str, list_t *env, int n, char **command)
{
	int evalue = 0;

	if (str[1] != NULL)
		evalue = catoi(str[1]);
	if (evalue == -1)
	{
		illegalnumber(str[1], n, env);
		freedoubleptr(str);
		return (2);
	}
	freedoubleptr(str);
	freelinkedlist(env);
	if (command != NULL)
		freedoubleptr(command);
	exit(evalue);
}
