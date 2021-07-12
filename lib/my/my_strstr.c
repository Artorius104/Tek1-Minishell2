/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** test_strstr.c
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int j;

    for (int i = 0; str[i] != '\0'; i++) {
        for (j = 0; str[j + i] == to_find[j]; j++)
            if (to_find[j + 1] == '\0')
                return str + i;
    }

    return NULL;
}
