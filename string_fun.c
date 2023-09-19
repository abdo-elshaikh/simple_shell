#include "shell.h"
/**
 * str_cmp - compare two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, 1 if s1 > s2, -1 if s1 < s2
*/
int str_cmp(char *s1, char *s2)
{
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
            return (0);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

/**
 * str_cat - concatenate two strings
 * @s1: first string
 * @s2: second string
 * Return: concatenated string
*/
char *str_cat(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *str;

    str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
    if (!str)
        return (NULL);

    while (s1[i]!= '\0')
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}
/**
 * str_cpy - copy a string
 * @s1: string to copy
 * @s2: string to copy
 * Return: copied string
*/
char *str_cpy(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *str;

    str = malloc(sizeof(char) * (strlen(s2) + 1));
    if (!str)
        return (NULL);

    while (s2[j]!= '\0')
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}

/**
 * str_dup - duplicate a string
 * @s1: string to duplicate
 * Return: duplicated string
*/
char *str_dup(char *s1)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (strlen(s1) + 1));
    if (!str)
        return (NULL);
    while (s1[i]!= '\0')
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
