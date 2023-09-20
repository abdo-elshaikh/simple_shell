#include "hsh.h"
/**
 * new_process - creates new process to execute command
 * @args: array of command arguments
 *
 * Return: process ID
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	char *path = getenv("PATH");

	if (path == NULL || strlen(path) == 0)
	{
		fprintf(stderr, "Error: PATH environment variable is not set.\n");
		return (-1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Execution failed");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Forking failed");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
