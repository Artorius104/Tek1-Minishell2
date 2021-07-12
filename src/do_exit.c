/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-minishell1-gilbert.badiabo
** File description:
** my_cmd.c
*/

#include "minishell.h"

void do_exit(char **copy)
{
    if (my_strcmp(copy[0], "exit") != 0)
        return;
    my_putstr("exit\n");
    exit(0);
}