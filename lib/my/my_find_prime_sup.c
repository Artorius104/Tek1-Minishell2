/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_find_prime_sup.c
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (int i = nb; i <= 32768; i++) {
        if (my_is_prime(i) == 1)
            return (i);
    }
    return 0;
}