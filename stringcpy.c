#include "main.h"
/**
 * stringcpy - copies src string to dest
 * @dest: copy to this
 * @src: copy this
 * Return: new dest string
 */
char stringcpy(char *dest, char *src)
{
	int i, length;

	for (length = 0; src[length] != '\0'; length++)
		;
	for (i = 0; i <= length; i++)
		dest[i] = src[i];
	return (dest);
}
