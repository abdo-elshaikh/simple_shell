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
    return (-1);
}

/**
 * shell_exit - exit
 * @args: array of arguments
 * Return: 1 on success
 */
int shell_exit(char **args)
{
    /*exit with status 0*/
    if (args[1] == NULL)
    {
        fprintf(stderr, "exit: too few arguments\n");
        return (0);
    }
    else
    {
        fprintf(stderr, "exit: %s\n", args[1]);
        exit(atoi(args[1]));
    }
}

/**
 * shell_help - print help
 * @args: array of arguments
 * Return: 1 on success
 */
int shell_help(char **args)
{
    char *help[] = {
        "cd",
        "exit",
        "env",
        "setenv",
        "unsetenv",
        "help",
    };
    long unsigned int i = 0;
    (void)args;

    /* print help */
    printf("\n Shell built-in commands:\n");
    printf("Usage: %s [command]\n", args[0]);
    printf("\n");
    printf("Available commands:\n");

    for (i = 0; i < sizeof(help) / sizeof(help[0]); i++)
    {
        printf("%s\n", help[i]);
    }
    printf("use \"help [command]\" for more information\n");
    return (-1);
}
