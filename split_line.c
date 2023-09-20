#include "hsh.h"
/**
 * split_input_line - tokenize input string
 * @line: input string
 * Return: array of tokens
 */
char **split_input_line(char *line)
{
	int buffer_size = 64;
	int i = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error in split_input_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[i] = token;
		i++;
		if (i >= buffer_size)
		{
			buffer_size += buffer_size;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "reallocation error in split_input_line: tokens");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;

	if (!tokens && i > 0)
	{
		free(tokens);
		fprintf(stderr, "reallocation error in split_input_line: tokens");
		exit(EXIT_FAILURE);
	}
	return (tokens);
}
