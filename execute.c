#include "shell.h"

/**
 * execute_command - execute a command and map if command is a builtin
 * @args: array of tokens
 * Return: 1 on success 0 on failure
 */
int execute_command(char **args)
{
    if (args[0] == NULL)
    {
        return (0);
    }
    else if (strcmp(args[0], "cd") == 0)
    {
        return (shell_cd(args));
    }
    else if (strcmp(args[0], "exit") == 0)
    {
        return (shell_exit(args));
    }
    else if (strcmp(args[0], "env") == 0)
    {
        return (shell_env(args));
    }
    else if (strcmp(args[0], "setenv") == 0)
    {
        return (shell_setenv(args));
    }
    else if (strcmp(args[0], "unsetenv") == 0)
    {
        return (shell_unsetenv(args));
    }
    else if (strcmp(args[0], "help") == 0)
    {
        return (shell_help(args));
    }
    else
    {
        return (new_process(args));
    }
}