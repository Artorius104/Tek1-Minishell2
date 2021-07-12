/*
** EPITECH PROJECT, 2020
** stock_minishell
** File description:
** main.c
*/

#include "minishell.h"

char **copy_env(char **env)
{
    char **new = malloc(sizeof(char *) * 500);
    int i = 0;
    int f = 0;

    for (i = 0; env[i] != NULL; i++)
        new[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
    for (i = 0; env[i] != NULL; i++) {
        for (int j = 0; env[i][j] != '\0'; j++) {
            new[i][j] = env[i][j];
            new[i][j + 1] = '\0';
        }
        if (my_strncmp(new[i], "OLDPWD=", 7) == 0)
            f = 1;
    }
    new[i] = NULL;
    if (f == 0)
        new = my_setenv(new, "OLDPWD", NULL);
    return new;
}

int analyse_cmd(char **copy)
{
    if (my_strcmp(copy[0], "exit") == 0)
        return 1;
    if (my_strcmp(copy[0], "cd") == 0)
        return 1;
    if (my_strcmp(copy[0], "setenv") == 0)
        return 1;
    if (my_strcmp(copy[0], "unsetenv") == 0)
        return 1;
    if (my_strcmp(copy[0], "env") == 0)
        return 1;
    return 0;
}

void manage_cmd(char **env, char **tab, int i, int to_fork)
{
    char **copy = NULL;

    clean_line(tab[i]);
    if (check_pipe(tab[i]) == 1) {
        do_pipe(tab[i], env);
        return;
    }
    if (my_strlen(tab[i]) > 0) {
        copy = str_to_arr(tab[i], ' ');
        if (analyse_cmd(copy) == 0)
            exec_cmd(copy, env, to_fork);
        else
            env = exec_my_cmd(copy, env);
        free_arr(copy);
    }
}

int main(int ac, char *av[], char **nv)
{
    char **env = copy_env(nv);
    char *line = NULL;
    char **tab = NULL;
    int redir = 0;

    while (1) {
        line = get_cmd();
        tab = str_to_arr(line, ';');
        for (int i = 0; tab[i] != NULL; i++) {
            redir = check_redir(tab[i]);
            if (redir == 0)
                manage_cmd(env, tab, i, 1);
            else {
                do_redir(tab[i], redir, env);
            }
        }
        free(line);
        free_arr(tab);
    }
    free_arr(env);
    return 0;
}
