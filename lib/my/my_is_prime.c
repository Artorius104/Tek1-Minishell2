/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    if (nb == 0 || nb == 1)
        return 0;
    if (nb == 2)
        return 1;
    if ((nb % 2) == 0 && nb != 2)
        return 0;
    if (nb > 1){
        for (int i = 2; i < nb; i += 2) {
            if (nb % i == 0)
                return 0;
        }
    }
    return 1;
}
