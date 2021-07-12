/*
** EPITECH PROJECT, 2020
** stock_minishell
** File description:
** exec_my_cmd.c
*/

#include "minishell.h"

void print_error(int status)
{
    int sig;

    if (WIFSIGNALED(status)) {
        sig = WTERMSIG(status);
        if (WCOREDUMP(status)) {
            if (sig == 8)
                my_puterror("Floating exception (core dumped)\n");
            else
                my_puterror("Segmentation fault (core dumped)\n");
        } else {
            if (sig == 8)
                my_puterror("Floating exception\n");
            else
                my_puterror("Segmentation fault\n");
        }
    }
}

char **exec_my_cmd(char **copy, char **env)
{
    do_env(env, copy);
    env = do_setenv(env, copy);
    env = do_unsetenv(env, copy);
    do_exit(copy);
    env = do_cd(env, copy);
    return env;
}