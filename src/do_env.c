/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-minishell1-gilbert.badiabo
** File description:
** do_env.c
*/

#include "minishell.h"

void do_env(char **env, char **copy)
{
    if (my_strcmp(copy[0], "env") != 0)
        return;
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}