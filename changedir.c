#include "main.h"
/**
 * stringcat - joins two strings
 * @dest: char to be appended
 * @src: wat to append
 * Return: concatenated string
 */
char *stringcat(char *dest, char *src)
{
	int length = 0;
	int length2 = 0;
	int totallength = 0;
	int i = 0;

	while (dest[length] != '\0')
	{
		length++;
		totallength++;
	}
	while (src[length2] != '\0')
	{
		length2++;
		totallength++;
	}
	dest = _realloc(dest, length, sizeof(char) * totallength + 1);

	i = 1;

	while (src[i] != '\0')
	{
		dest[length] = src[i];
		length++;
		i++;
	}
	dest[length] = '\0';

	return (dest);
}
/**
 * setenvironment - sets env by cocatenating two strings first
 * @env: env variable
 * @name: name of env variable
 * @dir: directory path
 * Return: 0 upon success
 */
int setenvironment(list_t **env, char *name, char *dir)
{
	int ind = 0, i = 0;
	char *concat;
	list_t *hold;

	concat = _strdup(name);
	concat = stringcat(concat, "=");
	concat = stringcat(concat, dir);
	ind = findenvironment(*env, name);
	hold = *env;
	while (i < ind)
	{
		hold = hold->next;
		i++;
	}
	free(hold->var);
	hold->var = _strdup(concat);
	free(concat);
	return (0);
}

/**
 * changedironly - changes the dir to home
 * @env: bring in env linked list to update PATH and OLDPWD
 * @current: bring in cur wd
 */
void changedironly(list_t *env, char *current)
{
	char *home = NULL;

	home = getenvironment("HOME", env);
	setenvironment(&env, "OLDPWD", current);
	free(current);
	if (access(home, F_OK) == 0)
		chdir(home);
	current = NULL;
	current = getcwd(current, 0);
	setenvironment(&env, "PWD", current);
	free(current);
	free(home);
}
/**
 * cdexecute - executes the current dir
 * @env: bring in env linked list to update PATH and OLDPWD
 * @current: bring in cd
 * @dir: bring the path to change to
 * @str: bring in 1st arg to wite out error
 * @n: bring in line number
 * return: 0 if success 2 if fail
 */
int cdexecute(list_t *env, char *current, char *dir, char *str, int n)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		setenvironment(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		current = getcwd(current, 0);
		setenvironment(&env, "PWD", current);
		free(current);
	}
	else
	{
		cantcdto(str, n, env);
		free(current);
		i = 2;
	}
	return (i);
}
/**
 * changedir - change directory
 * @str: user command
 * @env: env variable
 * @n: nth user command
 * Return: 0 upon success
 */
int changedirectory(char **str, list_t *env, int n)
{
	char *current = NULL, *dir = NULL;
	int exitstat = 0;

	current = getcwd(current, 0);
	if (str[1] != NULL)
	{
		if (str[1][0] == '~')
		{
			dir = getenv("HOME", env);
			dir = stringcat(dir, str[1]);
		}
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
				dir = getenv("OLDPWD", env);
		}
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = stringcat(dir, "/");
				dir = stringcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		exitstat = cdexecute(env, current, dir, str[1], n);
		free(dir);
	}
	else
		changedironly(env, current);
	freedoubleptr(str);
	return (exitstat);
}
