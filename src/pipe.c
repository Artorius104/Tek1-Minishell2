/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-1-minishell2-gilbert.badiabo
** File description:
** pipe.c
*/

#include "minishell.h"

int check_pipe(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '|')
            return 1;
    return 0;
}

char *get_pipe_arg(char *line, int i)
{
    char *str = malloc(sizeof(char) * my_strlen(line));
    int k = 0;

    if (i == 0) {
        for (; line[i + 1] != '|'; ++k, ++i)
            str[k] = line[i];
        str[k] = '\0';
        return str;
    }
    for (; line[i] != '\0'; ++k, ++i)
        str[k] = line[i];
    str[k] = '\0';
    return str;
}

void do_pipe2(char *s1, char *s2, char **env, int *pipefd)
{
    int status = 0;
    pid_t client;

    client = fork();
    if (client == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        manage_cmd(env, &s2, 0, 0);
        exit(0);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    wait(&status);
    free(s1);
    free(s2);
    print_error(status);
}

void do_pipe(char *line, char **env)
{
    char *arg1 = get_pipe_arg(line, 0);
    char *arg2 = NULL;
    int pipefd[2];
    pid_t client;
    int status = 0;
    int i = 0;

    for (i = 0; line[i] != '|'; ++i);
    i += 2;
    arg2 = get_pipe_arg(line, i);
    pipe(pipefd);
    client = fork();
    if (client == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        manage_cmd(env, &arg1, 0, 0);
        exit(0);
    }
    wait(&status);
    print_error(status);
    do_pipe2(arg1, arg2, env, pipefd);
}