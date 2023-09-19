#include "shell.h"
/**
 * free_line - free a line
 * @line: line to free
 * Return: Nothing
*/
void free_line(char *line)
{
    free(line);
}

/**
 * free_line_array - free a line array
 * @line: line array to free
 * Return: Nothing
*/
void free_line_array(char **line)
{
    int i = 0;
    while (line[i] != NULL)
    {
        free(line[i]);
        i++;
    }
    free(line);
}

/**
 * free_args - free arguments
 * @args: arguments to free
 * Return: Nothing
*/
void free_args(char **args)
{
    int i = 0;
    while (args[i] != NULL)
    {
        free(args[i]);
        i++;
    }
    free(args);
}