#include "shell.h"
/**
 * replace_var - function to replace variables in a given string
 * @str: string to replace
 * Return: string
 */
char *replace_variables(char *str)
{
    char *output = NULL;
    int output_index = 0;
    int i;

    if (str == NULL)
        return NULL;

    output = malloc(sizeof(char) * BUFFER_SIZE);
    if (output == NULL)
    {
        perror("malloc");
        return NULL;
    }

    while (*str != '\0')
    {
        switch (*str)
        {
            case '$':
                if (*(str + 1) == '$')
                {
                    pid_t pid = getpid();
                    char pid_str[BUFFER_SIZE];
                    int pid_len = snprintf(pid_str, BUFFER_SIZE, "%d", pid);
                    for (i = 0; i < pid_len; i++)
                        output[output_index++] = pid_str[i];
                }
                else if (*(str + 1) == '>')
                {
                    int status_len = snprintf(NULL, 0, "%d", last_command_status);
                    char status_str[status_len + 1];
                    snprintf(status_str, status_len + 1, "%d", last_command_status);
                    for (i = 0; i < status_len; i++)
                        output[output_index++] = status_str[i];
                }
                else if (*(str + 1) == '!')
                {
                    int exit_len = snprintf(NULL, 0, "%d", WEXITSTATUS(last_command_status));
                    char exit_str[exit_len + 1];
                    snprintf(exit_str, exit_len + 1, "%d", WEXITSTATUS(last_command_status));
                    for (i = 0; i < exit_len; i++)
                        output[output_index++] = exit_str[i];
                }
                else
                {
                    output[output_index++] = '$';
                    output[output_index++] = *(str + 1);
                }
                str++;
                break;
                
            default:
                output[output_index++] = *str;
                break;
        }
        
        str++;
    }

    output[output_index] = '\0';
    return output;
}
