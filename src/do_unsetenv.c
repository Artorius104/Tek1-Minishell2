/*
** EPITECH PROJECT, 2020
** stock_minishell
** File description:
** do_unsetenv.c
*/

#include "minishell.h"

char **rm_env(char **env, int pos)
{
    int i;

    for (i = pos; env[i] != NULL; i++)
        env[i] = env[i + 1];
    env[i] = NULL;
    return env;
}

char **do_unsetenv(char **env, char **copy)
{
    int i = 0;
    int j = 0;
    char *cat = NULL;
    int len = 0;

    if (my_strcmp(copy[0], "unsetenv") != 0)
        return env;
    for (j = 1; copy[j] != NULL; j++) {
        cat = my_strcat(copy[j], "=");
        len = my_strlen(cat);
        for (i = 0; env[i] != NULL; i++) {
            if (my_strncmp(cat, env[i], len) == 0) {
                env = rm_env(env, i);
                i--;
            }
        }
        free(cat);
    }
    return env;
}