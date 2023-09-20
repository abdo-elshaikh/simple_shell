#include "hsh.h"
/**
 * add_directory_to_path - add directory to  PATH environment variable
 * @directory: directory to add
 *
 * this function adds  specified directory to  PATH environment variable
 */
void add_directory_to_path(char *directory)
{
	char *current_path = get_environment("PATH");
	char new_path[BUFFER_SIZE];

	sprintf(new_path, "%s:%s", current_path, directory);
	set_environment("PATH", new_path);
}

/**
 * remove_directory_from_path - remove directory from PATH environment variabl
 * @directory:  directory to remove
 *
 * function removes specified directory from PATH environment variable
 */
void remove_directory_from_path(char *directory)
{
	char *current_path = get_environment("PATH");
	char *token;
	char new_path[BUFFER_SIZE] = "";

	token = strtok(current_path, ":");
	while (token != NULL)
	{
		if (strcmp(token, directory) != 0)
		{
			strcat(new_path, token);
			strcat(new_path, ":");
		}
		token = strtok(NULL, ":");
	}
	new_path[strlen(new_path) - 1] = '\0';
	set_environment("PATH", new_path);
}
/**
 * parse_command - Parses a command into an array of arguments.
 * @command: The command to parse.
 *
 * Return: An array of arguments.
 */
char **parse_command(char *command)
{
	int buffer_size = BUFFER_SIZE;
	int position = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(command, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		position++;

		if (position >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
