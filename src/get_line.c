/*
** EPITECH PROJECT, 2020
** stock_minishell
** File description:
** clean_line.c
*/

#include "minishell.h"

char *rm_char(char *str, int pos)
{
    int i;

    for (i = pos; str[i] != '\0'; i++)
        str[i] = str[i + 1];
    str[i] = '\0';
    return str;
}

char  *clean_line(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    while (str[0] == ' ')
        rm_char(str, 0);
    for (int i = my_strlen(str) - 1; i > 0; i--)
        if (str[i] == ' ')
            str[i] = '\0';
        else
            break;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i - 1] == ' ') {
            rm_char(str, i);
            i--;
        }
    }
    return str;
}

char *get_cmd(void)
{
    char *line = NULL;
    size_t size = 0;
    int len;

    my_putstr("$>");
    if (getline(&line, &size, stdin) == -1) {
        my_putstr("exit\n");
        exit(0);
    }
    len = my_strlen(line);
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
    clean_line(line);
    return line;
}