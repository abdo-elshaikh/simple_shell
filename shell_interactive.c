#include "shell.h"
/**
 * shell_interactive - command line interpreter
 * Return: Nothing
 */
void shell_interactive(void)
{
    char *command;
    char **args;
    int status = 0;

    do
    {
        printf(PROMPT);
        command = read_line();
        args = split_line(command);
        status = execute_command(args);
        free_line(command);
        free_line_array(args);
        
    } while (status);
}
