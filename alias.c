#include "shell.h"
int alias_count = 0;
alias_t alias[MAX_ALIAS];
/**
 * print_alias - print alias
 * @alias: alias
 * Return: Nothing
 */
void print_alias(void)
{
    int i;

    for (i = 0; alias[i].name != NULL; i++)
    {
        printf("%s = %s\n", alias[i].name, alias[i].value);
    }
}

/**
 * print_specefic_alias - print specific alias
 * @alias: alias
 * Return: Nothing
 */
void print_specefic_alias(char **args)
{
    int i, j;

    for (i = 0; args[i] != NULL; i++)
    {
        for (j = 0; j < alias_count; j++)
        {
            if (strcmp(alias[j].name, args[i]) == 0)
            {
                printf("%s = %s\n", alias[j].name, alias[j].value);
                break;
            }
        }
    }
}

/**
 * define_alias - Function to define or update aliases
 * @alias: alias
 * Return: Nothing
 */
void define_alias(char **args)
{
    char *name, *value;
    int i = 0;
    name = strtok(args, "=");
    value = strtok(NULL, "\n");

    if (name == NULL || value == NULL)
    {
        fprintf(stderr, "%s\n", "Invalid syntax");
        }
    /* Check if alias exists and update its value */
    for (i = 0; alias[i].name != NULL; i++)
    {
        if (strcmp(alias[i].name, name) == 0)
        {
            free(alias[i].value);
            alias[i].value = value;
            break;
        }
    }
    /* Add new alias if not exists */

    if (alias[i].name == NULL)
    {
        if (alias_count >= MAX_ALIAS)
        {
            fprintf(stderr, "%s\n", "Too many aliases");
        }
        else
        {
            alias[alias_count].name = name;
            alias[alias_count].value = value;
            alias_count++;
        }
    }
}

