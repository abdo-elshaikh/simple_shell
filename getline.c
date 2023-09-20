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
 *
 * Return: The read line (including newline), or NULL on failure or EOF
 */
char *get_line()
{
	char *line = NULL;
	size_t buffer_size = 0;

	getline(&line, &buffer_size, stdin);
	line[strcspn(line, "\n")] = '\0';
	return (line);
}
