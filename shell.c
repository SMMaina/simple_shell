#include "main.h"

/**
 * shell - a UNIX command line interpreter
 * @ac: command line arguments
 * @av: a NULL terminated array of strings
 * @env: a NULL terminated array of strings
 * Return: void
 */

void shell(int ac, char **av, char **env)
{
	char *line;
	char **args;
	int status = 1;
	char *tmp = NULL;
	char *er;
	char *filename;
	int flow;
	
	er = "Error";
	do {
		prompt();
		line = _getline();
		args = split_line(line);
		flow = bridge(args[0], args);
		if (flow == 2)
		{
			filename = args[0];
			args[0] = find_path(args[0], tmp, er);
			if (args[0] == er)
			{
				args[0] = search_cwd(filename, er);
				if (args[0] == filename)
					write(1, er, 5);
			}
		}
		if (args[0] != er)
			status = execute_prog(args, line, env, flow);
		free(line);
		free(args);
	} while (status);
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;
}
