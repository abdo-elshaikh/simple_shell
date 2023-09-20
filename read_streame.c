#include "hsh.h"
/**
 * read_stream_input - read input from stream
 *
 * Return: input line
 */

char *read_stream_input(void)
{
	int buffer_size = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * buffer_size);
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream_input");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		character = getchar();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}

		line[i] = character;
		i++;

		if (i >= buffer_size)
		{
			buffer_size += buffer_size;
			line = realloc(line, buffer_size);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream_input");
				exit(EXIT_FAILURE);
			}
		}
	}
}
