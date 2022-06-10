#include "main.h"
#include <stdio.h>

/**
 * get_input - function that gets the data input by the user
 * @lineptr: arg to pass to the function
 * Return: 0 upon success
 */
char **get_input(char *lineptr)
{
	char **argv = NULL;
	char *tok = NULL;
	char *delim[1] = {" \t\n\r"};
	int i = 0;

	tok = strtok(lineptr, *delim);
	i = 0;

	while (tok != NULL && i < 50)
	{
		argv[i] = tok;
		if (!strcmp("exit", argv[0]))
			exit(1);
		tok = strtok(NULL, *delim);
		i++;
		printf("%s\n", argv[0]);
	}
	argv[i] = NULL;
	return (argv);
}
