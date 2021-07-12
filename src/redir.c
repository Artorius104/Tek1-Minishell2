/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-1-minishell2-gilbert.badiabo
** File description:
** redir.c
*/

#include "minishell.h"

int check_redir(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '>') {
            if (line[i + 1] == '>')
                return 2;
            return 1;
        }
    return 0;
}

void simple_redir(char *s1, char *s2, int save, char **env)
{
    pid_t pid;
    int status = 0;
    int fd = open(s2, O_CREAT | O_RDWR | O_APPEND, 0777);

    pid = fork();
    if (pid == 0) {
        fd = open(s2, O_CREAT | O_RDWR | O_TRUNC, 0777);
        dup2(fd, 1);
    	manage_cmd(env, &s1, 0, 1);
        exit(0);
    } else {
        wait(&status);
        dup2(1, save);
    }
    print_error(status);
    close(save);
    close(fd);
}

void double_redir(char *s1, char *s2, int save, char **env)
{
    pid_t pid;
    int status = 0;
    int fd = open(s2, O_CREAT | O_RDWR | O_APPEND, 0777);

    pid = fork();
    if (pid == 0) {
        fd = open(s2, O_CREAT | O_RDWR | O_APPEND, 0777);
        dup2(fd, 1);
    	manage_cmd(env, &s1, 0, 1);
        free(s1);
        free(s2);
        exit(0);
    } else {
        wait(&status);
        dup2(1, save);
    }
    print_error(status);
    close(save);
    close(fd);
}

void do_redir(char *line, int redir, char **env)
{
    char *arg1 = get_redir_arg(line, 0);
    char *arg2 = NULL;
    int i = 0;
    int save = dup(1);

    for (i = 0; line[i] != '>'; ++i);
    if (line[i + 1] == '>')
        i += 3;
    else
        i += 2;
    arg2 = get_redir_arg(line, i);
    if (redir == 1)
        simple_redir(arg1, arg2, save, env);
    else
        double_redir(arg1, arg2, save, env);
    free(arg1);
    free(arg2);
}