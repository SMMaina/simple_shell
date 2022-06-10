#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 * description - this contains the unique identifier of the process
 * Return: 0 upon success
 */
int main(void)
{
	pid_t my_proid;
	pid_t my_pproid;

	my_proid = getpid();
	printf("This is PID: %u\n", my_proid);

	my_pproid = getppid();
	printf("This is PPID: %u\n", my_pproid);
	return (0);
}
