#include "shell.h"

/*
 * _strcpy - function top copy string
 * @str: string has been copy
 * @src: string we want to copy
 * Return: str
 */

char *_strcpy(char *str, char *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}

/*
 * _strlen - function to get lenght of string
 * @str: string has been get lenght
 * Return: lenght of string
 */
int _strlen(const char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return (i);
}