#include "main.h"

/**
 * freedoubleptr - frees the malloced arrays
 * @str: array of strings
 */
void freedoubleptr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
