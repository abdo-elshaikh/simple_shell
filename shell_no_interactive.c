#include "shell.h"
/**
 * shell_no_interactive - command line interpreter
 * Return: Nothing
*/
void shell_no_interactive(void)
{
    char *command;
    char **args = NULL;
    int status = -1;

    do
    {
        printf(PROMPT);
        command = read_line();
        args = split_line(command);
        status = execute_command(args);
        free_line(command);
        free_line_array(args);
        if (status >= 0)
            exit(status);
    } while (status == -1);
}
