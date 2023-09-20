#include "hsh.h"
/**
 * redirect_input - redirect standard input from a file
 * @filename: name of input file
 * Return: 0 on success, -1 on failure
 */
int redirect_input(char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd < 0)
	{
		perror("Error opening input file");
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}
/**
 * redirect_output - redirect standard output to a file
 * @filename: Name of  output file
 *
 * Return: 0 on success, -1 on failure
 */
int redirect_output(char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fd < 0)
	{
		perror("Error opening output file");
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
