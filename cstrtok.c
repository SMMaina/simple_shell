#include "main.h"
/**
 * ctsize - returns no of dels
 * @str: user's command
 * @del: del
 * Return: no of tokens
 */
int ctsize(char *str, char del)
{
	int j = 0, ndel = 0;

	while (str[j] != '\0')
	{
		if (str[j] == del)
		{
			ndel++;
		}
		j++;
	}
	return (ndel);
}
/**
 * cstrtok - tokenizes a string
 * @str: user's command
 * @del: delimeter
 * Return: array of tokens
 */
char **cstrtok(char *str, char *del)
{
	int buf = 0, p = 0, si = 0, length = 0, s = 0, i = 0;
	char **toks = NULL, dch;

	dch = del[0];
	buf = ctsize(str, dch);
	toks = malloc(sizeof(char *) * (buf + 2));
	if (toks == NULL)
		return (NULL);
	while (str[s] != '\0')
		s++;
	while (si < s)
	{
		length = stringlen(str, si, dch);
		toks[p] = malloc(sizeof(char) * (length + 1));
		if (toks[p] == NULL)
			return (NULL);
		while ((str[si] != dch) && (str[si] != '\0'))
		{
			toks[p][i] = str[si];
			i++;
			si++;
		}
		toks[p][i] = '\0';
		p++;
		si++;
	}
	toks[p] = NULL;
	return (toks);
}
