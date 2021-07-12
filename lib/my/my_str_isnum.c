/*
** EPITECH PROJECT, 2020
** CPool_Day06
** File description:
** my_str_isnum
*/

#include <stddef.h>

int my_str_isnum(char const *str)
{
    int dot = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && str[i] == '-')
            i++;
        if (str[i] == '.' && str[i - 1] <= '9' && str[i - 1]
        >= '0' && str[i + 1] <= '9' && str[i + 1] >= '0') {
            i++;
            dot++;
        }
        if (dot > 1)
            return 0;
        if (str[i] < 48 || str[i] > 57)
            return 0;
    }
    if (str == NULL)
        return 1;

    return 1;
}
