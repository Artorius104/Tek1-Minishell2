/*
** EPITECH PROJECT, 2020
** str_to_arr
** File description:
** str_to_arr
*/

//#include "n4s.h"
#include <stdlib.h>

int count_l(char *str, char c)
{
    int countline = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            countline++;
        }
        i++;
    }
    return (countline);
}

int count_c(char *str, int i, char c)
{
    int countcarac = 0;

    while (str[i] != '\0') {
        if (str[i] != c)
            countcarac++;
        i++;
    }
    return (countcarac);
}

char **str_to_arr(char *str, char c)
{
    int countl = count_l(str, c) + 1;
    char **tab = malloc(sizeof(char *) * (countl + 1));
    int i = 0;
    int tab1 = 0;
    int tab2 = 0;

    while (tab1 != countl) {
        tab[tab1] = malloc(sizeof(char) * (count_c(str, i, c) + 1));
        while (str[i] != c && str[i] != '\0'){
            tab[tab1][tab2] = str[i];
            i++;
            tab2 = tab2 + 1;
        }
        tab[tab1][tab2] = '\0';
        tab2 = 0;
        tab1 = tab1 + 1;
        i++;
    }
    tab[tab1] = NULL;
    return (tab);
}

void free_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
