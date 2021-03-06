#include "main.h"
/**
 * stringcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if same
 */
int stringcmp(char *str1, char *str2)
{
	int i = 0;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i))
		i++;
	if (*(str2 + i))
		return (*(str1 + i) - *(str2 + i));
	else
		return (0);
}
