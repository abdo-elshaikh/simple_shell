#include "shell.h"

/**
 * execute_command - execute a command and map if command is a builtin
 * @args: array of tokens
 * Return: 1 on success 0 on failure
 */
int execute_command(char **args)
{
    if (args[0] == NULL || args[0][0] == '\0')
        return (1);

    if (strcmp(args[0], "exit") == 0)
        return (shell_exit(args));
    if (strcmp(args[0], "pwd") == 0)
        return (shell_pwd(args));
    if (strcmp(args[0], "cd") == 0)
        return (shell_cd(args));
    if (strcmp(args[0], "env") == 0)
        return (shell_env(args));
    if (strcmp(args[0], "setenv") == 0)
        return (shell_setenv(args));
    if (strcmp(args[0], "unsetenv") == 0)
        return (shell_unsetenv(args));
    if (strcmp(args[0], "env") == 0)
        return (shell_env(args));
    if (strcmp(args[0], "help") == 0)
        return (shell_help(args));
    if (strcmp(args[0], "clear") == 0)
        return (shell_clear(args));
    if (strcmp(args[0], "alias") == 0)
        return (shell_alias(args));
    if (strcmp(args[0], "echo") == 0)
        return (shell_echo(args));

    int input = STDIN_FILENO;
    int output = STDOUT_FILENO;
    int append = 0;
    int i;
    int status;

    for (i = 0; args[i] != NULL; i++)
    {
        if (strcmp(args[i], "<") == 0)
        {
            if (args[i + 1] != NULL)
            {
                input = open(args[i + 1], O_RDONLY);
                if (input == -1)
                    return (1);
                args[i] = NULL;
                i++;
                append = 0;
            }
            else
                return (1);
        }
        else if (strcmp(args[i], ">") == 0)
        {
            if (args[i + 1] != NULL)
            {
                output = open(args[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
                if (output == -1)
                    return (1);
                args[i] = NULL;
                i++;
                append = 1;
            }
            else
                return (1);
        }
        else if (strcmp(args[i], ">>") == 0 || strcmp(args[i], ">>") == 0)
        {
            if (args[i + 1] != NULL)
            {
                output = open(args[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
                if (output == -1)
                    return (1);
                args[i] = NULL;
                i++;
                append = 1;
            }
        }
        else
        {
            fprintf(stderr, "%s: command not found\n", args[0]);
            return (1);
        }
    }

    pid_t pid;

    pid = fork();
    if (pid == 0)
    {

        if (input != STDIN_FILENO)
        {
            if (dup2(input, STDIN_FILENO) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(input);
        }
        if (output != STDOUT_FILENO)
        {
            if (dup2(output, STDOUT_FILENO) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(output);
        }
        if (append)
            args[i] = NULL;
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (input != STDIN_FILENO)
            close(input);
        if (output != STDOUT_FILENO)
            close(output);
        waitpid(pid, &status, 0);
        last_command_status = WIFEXITED(status) ? WEXITSTATUS(status) : 1;
        return (last_command_status);
        
    }
}
