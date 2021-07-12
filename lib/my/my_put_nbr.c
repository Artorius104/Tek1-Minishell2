/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (nb >= 0 && nb <= 9) {
        nb = nb + 48;
        my_putchar(nb);
    }
    return 0;
}