#include "hsh.h"
/**
 * handle_variables - handles variable replacement in command arguments
 * @args: array of command arguments
 */
void handle_variables(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		char *arg = args[i];

		if (arg[0] == '$')
		{
			if (strcmp(arg, "$") == 0)
			{
				char pid[16];

				sprintf(pid, "%d", getpid());
				free(args[i]);
				args[i] = strdup(pid);
			}
			else if (strcmp(arg, "$?") == 0)
			{
				int last_exit_status = -1;
				char exit_status_str[4];

				snprintf(exit_status_str, sizeof(exit_status_str), "%d", last_exit_status);
				free(args[i]);
				args[i] = strdup(exit_status_str);
			}
			else
			{
				char *var_name = arg + 1;
				char *value = get_environment(var_name);

				if (value != NULL)
				{
					free(args[i]);
					args[i] = strdup(value);
				}
			}
		}
		i++;
	}
}

/**
 * handle_exit - handles the exit command
 * @status: The exit status
 */
void handle_exit(char *status)
{
	int exit_status = atoi(status);

	exit(exit_status);
}

/**
 * handle_comments - handles comments in a command
 * @command: The command to handle
 */
void handle_comments(char *command)
{
	char *comment = strchr(command, '#');

	if (comment != NULL)
	{
		*comment = '\0';
	}
}

/**
 * handle_special_cases - handles special cases in command handling
 * @arguments: Array of command arguments
 *
 * Return: -1 on error, 0 on success.
 */
int handle_special_cases(char **arguments)
{
	if (arguments[0] == NULL)
	{
		fprintf(stderr, "No command provided.\n");
		return (-1);
	}
	if (arguments[0][0] == '/')
	{
		fprintf(stderr, "Command not found: %s\n", arguments[0]);
		return (-1);
	}
	if (strcmp(arguments[0], "ls") == 0)
	{
		return (-1);
	}
	if (strcmp(arguments[0], "ls") == 0 && arguments[1] == NULL)
	{
		fprintf(stderr, "ls: missing operand\n");
		return (-1);
	}
	if (arguments[0] != NULL && arguments[1] != NULL &&
			strcmp(arguments[0], "path") == 0 && strcmp(arguments[1], "$PATH") == 0)
	{
		return (-1);
	}
	if (execute_command(arguments) == -1)
	{
		fprintf(stderr, "%s: command not found\n", arguments[0]);
		return (-1);
	}
	return (0);
}

/**
 * handle_signal - handles signals
 * @signo: signal number
 */
void handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		printf("\nReceived SIGINT signal. Exiting...\n");
		exit(0);
	}
}

