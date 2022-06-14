#include "main.h"
#include <stdio.h>
/**
 * printalpha - function to print the alphabet
 * Return: always 0 upn success
 */
void printalpha(void)
{
	char a;

	for (a = 'a'; a <= 'z'; a++)
	{
		printf(a);
	}
	printf('\n');
}
