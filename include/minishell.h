/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** navy.h
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#include "my.h"
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <limits.h>

char *get_cmd(void);
char  *clean_line(char *str);
char **str_to_arr(char *str, char c);
void free_arr(char **arr);
void exec_cmd(char **copy, char **env, int to_fork);
void my_puterror(char *str);
char **exec_my_cmd(char **copy, char **env);
void do_env(char **env, char **copy);
char **do_setenv(char **env, char **copy);
char **my_setenv(char **env, char *name, char *arg);
char **do_unsetenv(char **env, char **copy);
void do_exit(char **copy);
char **do_cd(char **env, char **copy);
void print_error(int status);
int check_redir(char *line);
char *get_redir_arg(char *line, int i);
void do_redir(char *line, int redir, char **env);
void manage_cmd(char **env, char **tab, int i, int to_fork);
int check_pipe(char *line);
void do_pipe(char *line, char **env);

#endif