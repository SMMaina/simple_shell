#include <stdio.h>
#include <unistd.h>

/**
 * main - ppid
 * Return: 0
 */
int main(void)
{
	pid_t my_pproid;

	my_pproid = getppid();
	printf("This is PPID: %u\n", my_pproid);
	return (0);
}
