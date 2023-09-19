#include "shell.h"
/**
 * shell_cd - change directory
 * @args: array of arguments
 * Return: 1 on success
 */
int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "cd: no argument\n");
        return (1);
    }
    else if (chdir(args[1]) != 0)
    {
        fprintf(stderr, "cd: %s: No such file or directory\n", args[1]);
        return (1);
    }
    return (1);
}

/**
 * shell_exit - exit
 * @args: array of arguments
 * Return: 1 on success
 */
int shell_exit(char **args)
{
    if (args[1] != NULL)
    {
        fprintf(stderr, "exit: too many arguments\n");
    }
    exit(0);
}

/**
 * shell_help - print help
 * @args: array of arguments
 * Return: 1 on success
 */
int shell_help(char **args)
{

    if (strcmp(args[0], "help") == 0 && args[1] != NULL)
    {
        if (strcmp(args[1], "help") == 0)
            fprintf(stderr, "help: show this help\n");
        if (strcmp(args[1], "cd") == 0)
            fprintf(stderr, "cd: change directory\n");
        if (strcmp(args[1], "exit") == 0)
            fprintf(stderr, "exit: exit with status 0\n");
        if (strcmp(args[1], "env") == 0)
            fprintf(stderr, "env: print environment\n");
        if (strcmp(args[1], "setenv") == 0)
            fprintf(stderr, "setenv: set environment\n");
        if (strcmp(args[1], "unsetenv") == 0)
            fprintf(stderr, "unsetenv: unset environment\n");
    }
    else
        fprintf(stderr, " %s: command not found\n", args[1]);

    return (1);
}

/**
 * shell_clear - clear
 * @args: array of arguments
 * Return: 1 on success
*/
int shell_clear(char **args)
{
    if (args[1] != NULL)
    {
        fprintf(stderr, "clear: too many arguments\n");
        return (1);
    }
    system("clear");
    return (1);
}