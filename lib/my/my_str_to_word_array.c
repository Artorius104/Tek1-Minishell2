/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-minishell1-gilbert.badiabo
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h>

int len_word(char *str, char c, int n)
{
    int count = 0;

    for (int i = n; str[i] != '\0' && str[i] != c; i++)
        count++;
    count++;
    return count;
}

int count_word(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;
    count++;
    return count;
}

char **str_to_word_array(char *str, char c)
{
    char **arr = malloc(sizeof(char *) * count_word(str, c));
    int n = 0, i = 0, j = 0, k = 0;

    arr[0] = malloc(sizeof(char) * len_word(str, c, n));
    for (i = 0, j = 0, k = 0; str[k] != '\0'; k++) {
        if (str[k] != c) {
            arr[i][j] = str[k];
            j++;
        } else {
            arr[i][j] = '\0';
            i++;
            j = 0;
            arr[i] = malloc(sizeof(char) * len_word(str, c, i));
        }
    }
    arr[i + 1] = NULL;
    return arr;
}