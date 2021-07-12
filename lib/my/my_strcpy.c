/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_strcpy.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; i < my_strlen(src); i++)
        dest[i] = src[i];
    dest[i + 1] = '\0';

    return dest;
}
