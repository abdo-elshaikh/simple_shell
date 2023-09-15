#include "shell.h"
/**
 * read_stream - read a line from stream
 * Return: pointer to a string containing the line
 */
char *read_stream(void)
{
    char *line = NULL;
    size_t size = BUFFER_SIZE;
    size_t i = 0;
    int charcter;

    line = malloc(sizeof(char) * size);
    if (!line)
    {
        fprintf(stderr, "malloc error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        charcter = getchar();
        if (charcter == EOF)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        else if (charcter == '\0')
        {
            line[i] = '\0';
            return (line);
        }
        else
        {
            line[i] = charcter;
        }
        i++;
        if (i >= size)
        {
            size += size;
            line = realloc(line, size);
            if (!line)
            {
                fprintf(stderr, "realloc error");
                exit(EXIT_FAILURE);
            }
        }
    }
}