/*
** EPITECH PROJECT, 2020
** stock_minishell
** File description:
** exec_cmd.c
*/

#include "minishell.h"

char *concat_path(char **copy, char **path, int i)
{
    char *cat = NULL;
    char *f_path = NULL;

    cat = my_strcat(path[i], "/");
    f_path = my_strcat(cat, copy[0]);
    free(cat);
    return f_path;
}

int check_cmd(char *str)
{
    if (my_strlen(str) < 3)
        return 0;
    if (my_strncmp(str, "./", 2) != 0)
        return 0;
    if (opendir(str+2) != NULL) {
        my_puterror(str + 2);
        my_puterror(": Permission denied.\n");
        return 84;
    }
    return 0;
}

void do_cmd(char *path, char **copy, char **env, int to_fork)
{
    pid_t client;
    int status = 0;

    if (to_fork == 1) {
        client = fork();
        if (client == 0) {
            execve(path, copy, env);
            exit(0);
        } else
            wait(&status);
        print_error(status);
    } else {
        execve(path, copy, env);
        exit(0);
    }
}

char **get_path(char **env)
{
    int i = 0;

    for (i = 0; env[i] != NULL; i++)
        if (my_strncmp("PATH=", env[i], 5) == 0)
            return (str_to_arr(env[i] + 5, ':'));
    return NULL;
}

void exec_cmd(char **copy, char **env, int to_fork)
{
    char **path = get_path(env);
    char *f_path = NULL;
    int i = 0;

    if (access(copy[0], X_OK) == 0) {
        do_cmd(copy[0], copy, env, to_fork);
        free_arr(path);
        return;
    }
    if (path != NULL)
        for (i = 0; path[i] != NULL; i++) {
            f_path = concat_path(copy, path, i);
            if (access(f_path, X_OK) == 0) {
                do_cmd(f_path, copy, env, to_fork);
                free_arr(path);
                free(f_path);
                return;
            }
        }
    my_puterror(copy[0]);
    my_puterror(": Command not found.\n");
}