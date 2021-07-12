/*
** EPITECH PROJECT, 2020
** CPool_Day06
** File description:
** my_strncmp.c
*/

int  my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n; i++);
    if (s1[i] == s2[i])
        return 0;
    else
        return s1[i] - s2[i];
}
