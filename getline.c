#include "hsh.h"
/**
 * read_user_input - read input from user
 *
 * Return: input line
 */
char *read_user_input(void)
{
	char *line = NULL;
	size_t buffer_size = 0;

	if (getline(&line, &buffer_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Error while reading input");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
/**
 * get_line - Reads a line from standard input
 * @line: the line to read
 * @buffer_size: the size of the buffer
 * @stdin: standard input
 * Return: the number of bytes read or -1 on error
 */
int _getline(char **line, size_t *buffer_size, FILE *stdin)
{
	size_t bytes_read;
	char *buffer;
	int c;

	bytes_read = 0;
	buffer = malloc(*buffer_size);
	if (buffer == NULL)
	{
		perror("Error while allocating memory");
		exit(EXIT_FAILURE);
	}
	while ((c = fgetc(stdin)) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		buffer[bytes_read] = c;
		bytes_read++;
		if (bytes_read == *buffer_size)
		{
			*buffer_size *= 2;
			buffer = realloc(buffer, *buffer_size);
			if (buffer == NULL)
			{
				perror("Error while reallocating memory");
				exit(EXIT_FAILURE);
			}
		}
	}
	buffer[bytes_read] = '\0';
	*line = buffer;
	return (bytes_read);
}
