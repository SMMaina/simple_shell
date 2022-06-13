#include "main.h"

/**
 * stringcat - concatenates two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: new concat string
 */
char *stringcat(char *dest, char *src)
{
	int length = 0;
	int len2 = 0;
	int total = 0;
	int j = 0;

	while (dest[length] != '\0')
	{
		length++;
		total++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total++;
	}
	dest = _realloc(dest, length, sizeof(char) * total + 1);

	while (src[j] != '\0')
	{
		dest[length] = src[j];
		length++;
		j++;
	}
	dest[length] = '\0';
	return (dest);
}
