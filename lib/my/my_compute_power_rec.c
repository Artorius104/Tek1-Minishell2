/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_compute_power_rec.c
*/

int my_compute_power_rec(int nb, int p)
{
    int res;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    if (p >= 1)
        res = nb * my_compute_power_rec(nb, p - 1);
    return res;
}