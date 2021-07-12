/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_strncat.c
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);

    for (int j = 0; src[j] != '\0' && j < nb; i++, j++)
        dest[i] = src[j];
    dest[i] = '\0';

    return dest;
}