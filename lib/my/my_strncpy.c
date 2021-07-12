/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return dest;
}