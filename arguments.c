#include <stdio.h>
#include <unistd.h>

/**
 * main - prints all arguments
 * @argv: no of rgs passed to main
 * @argcount: array passed
 * Return: 0 upon success
 */
int main(int argcount, char **argv)
{
	int a = 0;
	pid_t myproid;
	pid_t mypproid;

	myproid = getpid();
	mypproid = getppid();

	if (argv)
	{
		while (*(argv[a]) != '\0' && a < argcount)
		{
			printf("argv[%d] = %s\n", a, argv[a]);
			a++;
		}
		printf("Prints %d arguments\nPID = %u\nPPID = %u\n", a++, myproid, mypproid);
		return (0);
	}
	return (-1);
}
