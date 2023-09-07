#include "shell.h"

// Function to read a line of input from the user
char *read_line()
{
    char *input = NULL;
    size_t buffer_size = 0;

    if (getline(&input, &buffer_size, stdin) == -1)
    {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    return input;
}

// Function to parse the input command into arguments
char **parse_input(char *input)
{
    int buffer_size = MAX_INPUT_LENGTH;
    int position = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if (!tokens)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= buffer_size)
        {
            buffer_size += MAX_INPUT_LENGTH;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}

// Function to execute a command
int execute_command(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        if (execvp(args[0], args) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main(void)
{
    char *input;
    char **args;
    int status;

    while (1)
    {
        printf("$ ");
        input = read_line();
        args = parse_input(input);
        status = execute_command(args);

        free(input);
        free(args);

        if (status == 0)
        {
            break;
        }
    }

    return 0;
}
