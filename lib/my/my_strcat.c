/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_strcat.c
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);

    for (int j = 0; src[j] != '\0' ; i++, j++)
        dest[i] = src[j];
    dest[i] = '\0';

    return dest;
}