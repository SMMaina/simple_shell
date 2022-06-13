#include "main.h"

/**
 * get_line - stores in a buffer the user's command
 * @str: buf
 * Return: no of char read
 */
size_t get_line(char **str)
{
	ssize_t i = 0, size = 0, t = 0; h = 0, n = 0;
	char buf[1024];

	while (h == 0 && (i = read(STDIN_FILENO, buf, 1024 - 1)))
	{
		if (i == -1)
			return (-1);
		buf[i] = '\0';

		n = 0;
		while (buf[n] != '\0')
		{
			if (buf[n] == '\n')
				h = 1;
			n++;
		}
		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = stringcpy(*str, buf);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = stringcat(*str, buf);
		}
	}
	return (size);
}
