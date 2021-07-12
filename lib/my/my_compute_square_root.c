/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_compute_square_root.c
*/

int is_whole_number(int nb)
{
    for (int i = 0; i <= 32767; i++) {
        if (i == nb)
            return 1;
    }

    return -1;
}

int my_compute_square_root(int nb)
{
    int res;

    if (is_whole_number(nb) == -1)
        return 0;
    if (nb <= 0)
        return 0;
    for (res = 0; res * res != nb; res++) {
        if (res > nb)
            return (0);
    }
    return res;
}