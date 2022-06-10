#include <stdio.h>
#include <stdlib.h>
/**
 * main - read the line
 * Return: 0 upon success
*/
int main(int argc, char *argv[], char **env)
{
	char *lineptr = NULL;
	char **in;
	char **pathenv;
	int i, j;
	size_t length = 0;
	ssize_t read;
	int childexe;
	int stat;

	while (1)
	{
		printf("#cisfun$> ");

		read = getline(&lineptr, &length, stdin);
		if (read == -1)
			break;

		in = get_input(lineptr);
		printf("VEFIFIED");

		pathenv = get_path(env);

		i = 0, j = 0;

		for (; *(in[i]) != '\0'; i++)
			printf("%s", in[i]);

		for (; pathenv[j] != '\0'; j++)
			printf("%s", pathenv[j]);

		childexe = fork();
		if (childexe == 0)
		{
			if (execve(in[0], in, NULL) == -1)
			{
				perror("Command not executed. Try again");
				exit(1);
			}
		}
		else
			wait(&status);
	}
	free(lineptr);
	return (0);
}

