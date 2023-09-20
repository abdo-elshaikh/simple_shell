#include "shell.h"

/**
 * execute_command - execute a command and map if command is a builtin
 *
 * @args: array of tokens
 * Return: 1 on success 0 on failure
 */
#include "shell.h"

int execute_command(char **args)
{
    int is_logical_operator = 0;
    int should_execute_next_command = 0;
    int i = 0;
    int result = 0;

    if (args == NULL || args[0] == NULL)
    {
        return 1;
    }

    while (args[i] != NULL)
    {

        if (strcmp(args[i], "&&") == 0)
        {
            is_logical_operator = 1;
        }
        else if (strcmp(args[i], "||") == 0)
        {
            is_logical_operator = 1;
        }
        else if (strcmp(args[i], ";") == 0)
        {
            i++;
            continue;
        }

        if (!is_logical_operator)
        {
            result = execute_single_command(args + i);
        }
        else
        {

            if (strcmp(args[i], "&&") == 0)
            {
                should_execute_next_command = (result == 0);
            }
            else if (strcmp(args[i], "||") == 0)
            {
                should_execute_next_command = (result != 0);
            }

            if (should_execute_next_command)
            {
                i++;
                result = execute_single_command(args + i);
            }
        }

        while (args[i] != NULL && strcmp(args[i], ";") != 0 && strcmp(args[i], "&&") != 0 && strcmp(args[i], "||") != 0)
        {
            i++;
        }

        if (args[i] != NULL)
        {
            i++;
        }
    }

    return (result);
}

/**
 * execute_single_command - execute a single command
 * @params: array of tokens
 * Return: 1 on success 0 on failure
 */
int execute_single_command(char **args)
{
    if (args == NULL || args[0] == NULL)
    {
        return 1;
    }

    if (strcmp(args[0], "cd") == 0)
    {
        return shell_cd(args);
    }
    else if (strcmp(args[0], "exit") == 0)
    {
        return shell_exit(args);
    }
    else if (strcmp(args[0], "help") == 0)
    {
        return shell_help(args);
    }
    else if (strcmp(args[0], "env") == 0)
    {
        return shell_env(args);
    }
    else if (strcmp(args[0], "setenv") == 0)
    {
        return shell_setenv(args);
    }
    else if (strcmp(args[0], "unsetenv") == 0)
    {
        return shell_unsetenv(args);
    }
    else if (strcmp(args[0], "pwd") == 0)
    {
        return shell_pwd(args);
    }
    else if (strcmp(args[0], "echo") == 0)
    {
        return shell_echo(args);
    }
    else if (strcmp(args[0], "clear") == 0)
    {
        return shell_clear(args);
    }
    else if (strcmp(args[0], "alias") == 0)
    {
        return shell_alias(args);
    }

    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("shell");
        return 1;
    }

    if (child_pid == 0)
    {

        execvp(args[0], args);
        perror("shell");
        exit(1);
    }
    else
    {
        int status;
        waitpid(child_pid, &status, 0);
        last_command_status = WEXITSTATUS(status);
        return last_command_status;
    }
}
