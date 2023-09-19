#include "shell.h"
/**
 * read_line - read a line from stdin
 * Return: pointer to a string containing the line
 */
char *read_line(void)
{
    char *line = NULL;
    size_t size = 0;

    if (getline(&line, &size, stdin) == -1)
    {
        if (feof(stdin))
        {
            free_line(line);
            fprintf(stderr, "fgets");
            exit(EXIT_SUCCESS);
        }
        else
        {
            free_line(line);
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}

/**
 * split_line - split a line into tokens
 * @line: line to split
 * Return: pointer to an array of tokens
 */
char **split_line(char *line)
{
    int buffer = BUFFER_SIZE;
    int i = 0;
    char **tokens = malloc(sizeof(char *) * buffer);
    char *token = NULL;

    if (!tokens)
    {
        perror("alloc error");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, DELIMITER); /* get first token */
    while (token)
    {
        /* handle comments */
        if (token[0] == '#')
        {
            break;
        }
        tokens[i] = token;
        i++;
        if (i >= buffer)
        {
            buffer += buffer;
            /* realloc tokens array */
            tokens = realloc(tokens, sizeof(char *) * buffer);
            if (!tokens)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIMITER);
    }
    tokens[i] = NULL;
    return (tokens);
}
