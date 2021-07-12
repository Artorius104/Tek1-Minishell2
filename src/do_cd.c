/*
** EPITECH PROJECT, 2020
** stock_minishell
** File description:
** do_cd.c
*/

#include "minishell.h"

void my_cd_dash(char **env)
{
    int i = 0;

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "OLDPWD=", 7) == 0) {
            chdir(env[i] + 7);
        }
    }
}

void my_cd_home(char **env)
{
    int i = 0;

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            chdir(env[i] + 5);
            return;
        }
    }
}

void my_cd(char **env, char **copy)
{
    if (copy[1] == NULL) {
        my_cd_home(env);
        return;
    }
    if (my_strcmp(copy[1], "-") == 0) {
        my_cd_dash(env);
        return;
    }
    chdir(copy[1]);
}

int error_cd(char **copy)
{
    if (copy[1] == NULL)
        return 0;
    if (my_strcmp(copy[1], "-") == 0)
        return 0;
    if (open(copy[1], O_RDONLY) == -1) {
        my_puterror(copy[1]);
        my_puterror(": No such file or directory.\n");
        return -1;
    }
    if (opendir(copy[1]) == NULL) {
        my_puterror(copy[1]);
        my_puterror(": Not a directory.\n");
        return -1;
    }
    return 0;
}

char **do_cd(char **env, char **copy)
{
    char *pwd = malloc(sizeof(char) * UCHAR_MAX);
    char *oldpwd = malloc(sizeof(char) * UCHAR_MAX);

    if (my_strcmp(copy[0], "cd") != 0)
        return env;
    if (error_cd(copy) != 0)
        return env;
    getcwd(oldpwd, UCHAR_MAX);
    my_cd(env, copy);
    getcwd(pwd, UCHAR_MAX);
    env = my_setenv(env, "PWD", pwd);
    free(pwd);
    env = my_setenv(env, "OLDPWD", oldpwd);
    free(oldpwd);
    return env;
}