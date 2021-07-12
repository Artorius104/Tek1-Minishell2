/*
** EPITECH PROJECT, 2020
** CPool_Day06
** File description:
** my_strupcase.c
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    return str;
}
