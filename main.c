#include "hsh.h"
/**
 * main - entry point
 * Description: main function to execute shell
 * Return: 0
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		start_shell_interactive();
	}
	else
	{
		start_shell_non_interactive();
	}
	return (0);
}

