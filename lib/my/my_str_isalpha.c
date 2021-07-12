/*
** EPITECH PROJECT, 2020
** CPool_Day06
** File description:
** my_str_isalpha
*/

#include <stddef.h>

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > 122 || str[i] < 97 && str[i] > 90 || str[i] < 65)
            return 0;
    if (str == NULL)
        return 1;

    return 1;
}
