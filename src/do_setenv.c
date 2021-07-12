/*
** EPITECH PROJECT, 2020
** stock_minishell
** File description:
** do_setenv.c
*/

#include "minishell.h"

char *get_setenv_arg(char *name, char *arg)
{
    char *foo = NULL;
    char *cat = NULL;

    if (arg == NULL)
        foo = my_strcat(name, "=");
    else {
        cat = my_strcat("=", arg);
        foo = my_strcat(name, cat);
        free(cat);
    }
    return foo;
}

char **my_setenv(char **env, char *name, char *arg)
{
    char *cat = NULL;
    char *foo = NULL;
    int i = 0;

    foo = get_setenv_arg(name, arg);
    cat = my_strcat(name, "=");
    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], cat, my_strlen(cat)) == 0) {
            free(cat);
            free(env[i]);
            env[i] = foo;
            return env;
        }
    }
    free(env[i]);
    env[i] = foo;
    env[i + 1] = NULL;
    return env;
}

int error_setenv(char **copy)
{
    int i = 0;

    for (i = 0; copy[i] != NULL; i++);
    if (i > 3)
        my_puterror("setenv: Too many arguments.\n");
    if ((copy[1][0] < 'a' || copy[1][0] > 'z')
        && (copy[1][0] < 'A' || copy[1][0] > 'Z')) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return -1;
    }
    for (int i = 0; copy[1][i] != '\0'; i++) {
        if ((copy[1][0] < 'a' || copy[1][0] > 'z')
            && (copy[1][0] < 'A' || copy[1][0] > 'Z')
            && (copy[1][0] < '0' || copy[1][0] > '9')) {
            my_puterror("setenv: Variable name");
            my_puterror("must contain alphanumeric characters.\n");
            return -1;
        }
    }
    return 0;
}

char **do_setenv(char **env, char **copy)
{
    if (my_strcmp(copy[0], "setenv") != 0)
        return env;
    if (copy[1] == NULL) {
        for (int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            my_putchar('\n');
        }
        return env;
    }
    if (error_setenv(copy) != 0)
        return env;
    env = my_setenv(env, copy[1], copy[2]);
    return env;
}