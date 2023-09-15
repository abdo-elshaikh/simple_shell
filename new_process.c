#include "shell.h"
/**
 * new_process - create a new process
 * @args: array of tokens
 * Return: 1 on success 0 on failure
 */
int new_process(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("./hsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("./hsh");
        exit(EXIT_FAILURE);
    }
    else
    {
        do
        {
            /*wait(&status);*/
            waitpid(pid, NULL, WUNTRACED);
        } while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
    }
    return (-1);
}