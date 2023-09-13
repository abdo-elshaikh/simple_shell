#include "shell.h"

/*
 * _strcpy - function To copy the value of one string to another
 * @str: string has been copy
 * @src: string we want to copy
 * Return: str
 */
char *_strcpy(char *str, char *src)
{
    int i = 0;

    while (src[i]!= '\0')
    {
        str[i] = src[i];
        i++;
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

/*
 * _strcmp - function to compare two string
 * @str1: string we want to compare
 * @str2: string we want to compare
 * Return: int
 */
int _strcmp(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i]!= '\0' && str2[i]!= '\0')
    {
        if (str1[i]!= str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return (0);
    else if (str1[i] == '\0')
        return (-1);
    else
        return (1);
}
/**
 * _strdup - function to duplcate string
 * @str1: string has been duplated
 * 
 * Return: new str
*/
char *_strdup(const char *str1)
{
    char *str;
    int i;

    str = malloc(sizeof(char) * (_strlen(str1) + 1));
    if (str == NULL)
        return (NULL);
    for (i = 0; str1[i]!= '\0'; i++)
    {
        str[i] = str1[i];
    }
    str[i] = '\0';
    return (str);
}
 
/**
 * _strcat - function to Concatenate str2 to str1
 * @str1: first string
 * @str2: second string
 * Return: full string
*/
char *_strcat(char *str1, char *str2)
{
    int i;
    int len1 = _strlen(str1);
    int len2 = _strlen(str2);

    str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (str == NULL)
        return (NULL);
    for (i = 0; i < len1; i++)
    {
        str[i] = str1[i];
    }
    for (i = 0; i < len2; i++)
    {
        str[i + len1] = str2[i];
    }
    str[i + len1] = '\0';
    return (str);
}

/**
 * _strrev - function to reverse string
 * @str: string has been reverse
 * Return: reversed string
 */
char *_strrev(char *str)
{
    int i = 0;
    int j = _strlen(str) - 1;
    char temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}

/**
 * _strchr - function to find a char in string
 * @str: string has been find a char
 * @c: char we want to find
 * Return: char
 */
char *_strchr(char *str, char c)
{
    int i = 0;
    while (str[i]!= '\0')
    {
        if (str[i] == c)
            return (&str[i]);
        i++;
    }
    return (NULL);
}

/**
 * _putchar - function to print charcter in stdout
 * @c: charcter
 * Return: 0 or 1
*/
int _putchar(char c)
{
    return (write(1, &c, 1));
}
// int _putchar(char c)
// {
//     write(STDOUT_FILENO, &c , sizeof(char));
//     return (1);
// }

/**
 * _putstr - function to print string
 * @str: string has been printing
 * Return: 
*/
int _putstr(char *str)
{
    int i = 0;
    while (str[i]!= '\0')
    {
        _putchar(str[i]);
        i++;
    }
    return (0);
}