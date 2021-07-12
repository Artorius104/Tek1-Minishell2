/*
** EPITECH PROJECT, 2020
** B-CPE-100-PAR-1-3-cpoolday04-gilbert.badiabo
** File description:
** my_putstr.c
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}