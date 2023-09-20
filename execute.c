#include "hsh.h"

/**
 * execute_command - Execute command or call a built-in function
 * @args: array of command arguments
 *
 * this function checks built-in function
 * and calls appropriate function
 * if not, it creates new process to execute command
 *
 * Return: 1 on success, 0 otherwise.
 */

int execute_command(char **args)
{
	char *builtin_functions[] = {
		"cd",
		"env",
		"help",
		"exit"};
	int (*builtin_pointers[])(char **) = {
		&change_directory,
		&print_environment,
		&show_help,
		&exit_shell};
	size_t i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}

	for (; i < sizeof(builtin_functions) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_functions[i]) == 0)
		{
			return ((*builtin_pointers[i])(args));
		}
	}

	return (new_process(args));
}

