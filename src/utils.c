/*
** EPITECH PROJECT, 2020
** stock_minishell
** File description:
** utils.c
*/

#include "minishell.h"

void my_puterror(char *str)
{
    if (str != NULL)
        write(2, str, my_strlen(str));
}

char *get_redir_arg(char *line, int i)
{
    char *str = malloc(sizeof(char) * my_strlen(line));
    int k = 0;

    if (i == 0) {
        for (; line[i + 1] != '>'; ++k, ++i)
            str[k] = line[i];
        str[k] = '\0';
        return str;
    }
    for (; line[i] != '\0'; ++k, ++i)
        str[k] = line[i];
    str[k] = '\0';
    return str;
}