#include "hsh.h"
/**
 * start_shell_non_interactive - unix command line interpreter
 * Return: void
 */
void start_shell_non_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = read_stream_input();
		args = split_input_line(line);
		status = execute_command(args);
		free(line);
		free(args);
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
