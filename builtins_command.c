#include "hsh.h"
/**
 * show_help - print help
 * @args: arguments
 * Return: 1 on success, 0 otherwise
 */
int show_help(char **args)
{
	char *builtin_functions[] = {
		"cd",
		"env",
		"help",
		"exit"};
	size_t i = 0;
	(void)(*args);

	printf("\n---help simple_shell---\n");
	printf("type a command and its arguments, then hit enter\n");
	printf("built-in commands:\n");

	for (; i < sizeof(builtin_functions) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_functions[i]);
	}

	printf("use the man command for infos on other programs.\n\n");
	return (-1);
}
/**
 * exit_shell - function to exit shell with status
 * @args: arguments
 * Return: 0 or 1
 */
int exit_shell(char **args)
{

	if (args[1] == NULL)
	{
		exit(0);
	}
	else
	{
		exit(atoi(args[1]));
	}
}

/**
 * change_directory - change current working directory
 * @args: array of command arguments
 * Return: 1 on success, 0 otherwise
 */
int change_directory(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in change_directory: Failed to change directory");
			return (-1);
		}
	}
	return (-1);
}
