#include "hsh.h"
/**
 * pipe_commands - pipes output of first command into second command
 * @command1: array of arguments for the first command
 * @command2: array of arguments for the second command
 * Return: 0 on success, -1 on failure
 */
int pipe_commands(char **command1, char **command2)
{
	int pipe_fd[2];
	pid_t pid1, pid2;

	if (pipe(pipe_fd) == -1)
	{
		perror("Failed to create pipe");
		return (-1);
	}

	pid1 = fork();
	if (pid1 == 0)
	{
		handleChildProcess1(pipe_fd, command1);
	}
	else if (pid1 < 0)
	{
		perror("Failed to fork first command");
		return (-1);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		handleChildProcess2(pipe_fd, command2);
	}
	else if (pid2 < 0)
	{
		perror("Failed to fork second command");
		return (-1);
	}

	closePipe(pipe_fd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}
/**
 * handleChildProcess1 - handles child process 1
 * @pipe_fd: pipe file descriptor
 * @command1: array of arguments for the first command
 * Return: Nothing
 */
void handleChildProcess1(int pipe_fd[], char **command1)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execute_command(command1);
	exit(EXIT_SUCCESS);
}
/**
 * handleChildProcess2 - handles child process 2
 * @pipe_fd: pipe file descriptor
 * @command2: array of arguments for the second command
 * Return: Nothing
 */
void handleChildProcess2(int pipe_fd[], char **command2)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	execute_command(command2);
	exit(EXIT_SUCCESS);
}
/**
 * closePipe - closes pipe
 * @pipe_fd: pipe file descriptor
 * Return: Nothing
 */
void closePipe(int pipe_fd[])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}
