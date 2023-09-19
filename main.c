#include "shell.h"
/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Exit status
 */
int main(int argc, char *argv[])
{
    char *command = NULL;
    char **args = NULL;
    int status = 0;

    if (argc > 1 && strcmp(argv[1], "-c") == 0)
    {
        if (argc < 3)
        {
            fprintf(stderr, "Usage: %s [-c]\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        command = argv[2];
        args = split_line(command);

        if (args == NULL)
        {
            fprintf(stderr, "Failed to split command line\n");
            exit(EXIT_FAILURE);
        }

        status = execute_command(args);

        free_line(command);
        free_line_array(args);

        exit(status);
    }
    else if (argc == 1)
    {
        shell_interactive();
    }
    else
    {
        fprintf(stderr, "Usage: %s [-c]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}