#include "shell.h"
/**
 * shell_clear - clear the shell
 * @args: array of arguments
 * Return: 0 on success
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

/**
 * shell_pwd - print the current working directory
 * @args: array of arguments
 * Return: 1 on success
 */
int shell_pwd(char **args)
{
    if (args[1] != NULL)
    {
        fprintf(stderr, "pwd: too many arguments\n");
        return (1);
    }
    printf("%s\n", getcwd(NULL, 0));
    return (1);
}

/**
 * shell_echo - echo
 * @args: array of arguments
 * Return: 1 on success
 */
int shell_echo(char **args)
{
    if (args[1] != NULL)
    {
        fprintf(stderr, "echo: too many arguments\n");
        return (1);
    }
    printf("%s\n", args[2]);
    return (1);
}