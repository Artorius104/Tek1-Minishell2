/*
** EPITECH PROJECT, 2020
** B-CPE-100-PAR-1-3-cpoolday04-gilbert.badiabo
** File description:
** my_strlen.c
*/

void my_putchar(char c);

int my_strlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}
