#include "main.h"
/**
 * nlength - count no of 0s in a tens no
 * @n: number
 * Return: returns count of digits
 */
int nlength(int n)
{
	int count = 0;
	int num = n;

	while (num > 9 || num < -9)
	{
		num /= 10;
		count++;
	}
	return (count);
}
/**
 * inttostring - turns an int to a string
 * @num: int
 * Return: returns int as a string and Null on failure
 */
char *inttostring(int num)
{
	int digits, tens, i = 0, t = 0, x;
	char *res;

	digits = num;
	tens = 1;

	if (num < 0)
		t = 1;
	res = malloc(sizeof(char) * (nlength(digits) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		res[i] = '-';
		i++;
	}
	for (x = 0; digits > 9 || digits < -9; x++)
	{
		digits /= 10;
		tens *= 10;
	}
	for (digits = num; x >= 0; x--)
	{
		if (digits < 0)
		{
			res[i] = (digits / tens) * -1 + '0';
			i++;
		}
		else
		{
			res[i] = (digits / tens) + '0';
			i++;
		}
		digits %= tens;
		tens /= 10;
	}
	res[i] = '\0';
	return (res);
}
