#include "main.h"
/**
 * main - to create a simple shell
 * @ac: count of args
 * @av: array of args
 * @env: env var
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	Prompt(env);

	return (0);
}
