#include "shell.h"
/**
 * shell_env - print environment
 * @args: array of arguments
 * Return: 0 on success
 */
int shell_env(char **args)
{
    int i;
    char **environ = environ;

    if (args[1] == NULL)
    {
        for (i = 0; environ[i] != NULL; i++)
        {
            printf("%s\n", environ[i]);
        }
        
    }
    else if (setenv(args[1], args[2], 1) != 0)
    {
        perror("setenv error");
        return (1);
    }
    return (-1);
    
}

/**
 * shell_setenv - set environment
 * @args: array of arguments
 * Return: 0 on success
 */
int shell_setenv(char **args)
{
    if (args[1] == NULL)
    {
        return (0);
    }
    else if (setenv(args[1], args[2], 1) != 0)
    {
        perror("setenv error");
        return (1);
    }
    return (-1);
}

/**
 * shell_unsetenv - unset environment
 * @args: array of arguments
 * Return: 0 on success
 */
int shell_unsetenv(char **args)
{
    if (args[1] == NULL)
    {
        return (0);
    }
    else if (unsetenv(args[1]) != 0)
    {
        perror("unsetenv error");
        return (1);
    }
    return (-1);
}
