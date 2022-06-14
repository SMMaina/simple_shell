#include "main.h"

/**
 * stringlen - returns token's string length
 * @str: token
 * @pos: index pos in user's command
 * @del: delimiter like " "
 * Return: token length
 */
int stringlen(char *str, int pos, char del)
{
	int len = 0;

	while ((str[pos] != del) && (str[pos] != '\0'))
	{
		pos++;
		len++;
	}
	return (len);
}
/**
 * tsize - returns no of dels ignoring continuous ones
 * @str: user's command
 * @del: delimeter
 * Return: no of delims
 */
int tsize(char *str, char del)
{
	int i = 0, numdel = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == del) && (str[i + 1] != del))
		{
			numdel++;
		}
		if ((str[i] == del) && (str[i + 1] == '\0'))
		{
			numdel--;
		}
		i++;
	}
	return (numdel);
}
/**
 * ignoredel - returns a string version with no delims
 * @str: user input command
 * @del: delimiter
 * Return: new string
 */
char *ignoredel(char *str, char del)
{
	while (*str == del)
		str++;
	return (str);
}
/**
 * stringtok - tokenizes a str and ret a string of tokens
 * @str: user's input
 * @del: delimter
 * @Return: an array of tokems
 */
char **_strtok(char *str, char *del)
{
	int buf = 0, p = 0, si = 0, i = 0, s = 0, t = 0;
	int length = 0;
	char **tokens = NULL, dch;

	dch = del[0];
	str = ignoredel(str, dch);
	buf = tsize(str, dch);
	tokens = malloc(sizeof(char *) * (buf + 2));
	if (tokens == NULL)
		return (NULL);
	while (str[s] != '\0')
		s++;
	while (si < s)
	{
		if (str[si] != dch)
		{
			length = stringlen(str, si, dch);
			tokens[p] = malloc(sizeof(char) * (length + 1));
			if (tokens[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != dch) && (str[si] != '\0'))
			{
				tokens[p][i] = str[si];
				i++;
				si++;
			}
			tokens[p][i] = '\0';
			t++;
		}
		if (si < s && (str[si + 1] != dch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	tokens[p] = NULL;
	return (tokens);
}
