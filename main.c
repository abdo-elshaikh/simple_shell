#include "shell.h"

/*
 * main - main function
 * @argc: get argument count
 * @argv: get argument vector
 * Return: 0
 */
int main(int argc, char argv[])
{
    if (argc!= 2)
    {
        _putstr("Usage:./shell <command>\n");
        return (0);
    }
    _putstr(argv[1]);
    _putchar('\n');
    return (0);
}