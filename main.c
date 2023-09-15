#include "shell.h"
/**
 * main - check if our shell is called
 * Return: 0 on success
*/
int main(void)
{
    if (isatty(STDIN_FILENO) == 1)
    {
        shell_interactive();
    }
    else
    {
        shell_no_interactive();
    }
    return (0);
}