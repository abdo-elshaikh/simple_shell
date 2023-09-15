#include "shell.h"
/**
 * shell_interactive - command line interpreter
 * Return: Nothing
 */
void shell_interactive(void)
{
    char *command;
    char **args = NULL;
    int status = 0;

    do
    {
        printf(PROMPT);
        /* read line from stdin */
        command = read_line();
        args = split_line(command);
        status = execute_command(args);
        free_line(command);
        free_line_array(args);
        if (status >= 0)
            exit(status);
    } while (status == -1);
}
