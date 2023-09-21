#include "hsh.h"
/**
 * start_shell_interactive - UNIX command line interpreter
 *
 * Return: void
 */
void start_shell_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf(PROMPT);
		line = read_user_input();
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
