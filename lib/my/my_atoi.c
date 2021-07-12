/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_atoi
*/

int	my_atoi(char const *str)
{
    int a = 1;
    int nb = 0;
    int i = 0;

    if (str[0] < '0' || str[0] > '9')
        return -84;
    while (str[i] <= ' ')
        i++;
    if (str[i] == '-') {
        a = a * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    return (nb * a);
}