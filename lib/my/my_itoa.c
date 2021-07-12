/*
** EPITECH PROJECT, 2020
** B-CPE-101-PAR-1-3-evalexpr-gilbert.badiabo
** File description:
** my_itoa.c
*/

#include <stdlib.h>

int nb_length(int nb)
{
    int div = 1;
    int count = 0;

    while ((nb / div) >= 1) {
        div *= 10;
        count++;
    }
    return count;
}

char *my_itoa(int nb)
{
    int length = nb_length(nb);
    char *str = malloc(sizeof(char) * length + 1);

    str[length] = '\0';
    while (length--) {
        str[length] = nb % 10  + '0';
        nb /= 10;
    }
    return str;
}