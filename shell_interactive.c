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
        /* read line from stdin */
        command = read_line();
        /* split line into tokens */
        args = split_line(command);
        /* execute command */
        status = execute_command(args);
        /* free allocated memory */
        free_line(command);
        free_line_array(args);
        
    } while (status);
}
