#include "main.h"
/**
 * _strdup - returns a ptr to a newly alloc space in mem
 * @str: string to duplicate
 * Return: ptr to duplicated string
 */
char *_strdup(char *str)
{
	char *dupstr;
	int i, length = 0;

	if (str == NULL)
		return (NULL);
	while (*(str + length))
		length++;
	length++;

	dupstr = malloc(sizeof(char) * length);
	if (dupstr == NULL)
		return (NULL);

	i = 0;
	while (i < length)
	{
		*(dupstr + i) = *(str + i);
		i++;
	}
	return (dupstr);
}
