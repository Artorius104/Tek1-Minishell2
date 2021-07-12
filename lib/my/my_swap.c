/*
** EPITECH PROJECT, 2020
** B-CPE-100-PAR-1-3-cpoolday04-gilbert.badiabo
** File description:
** my_swap.c
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int change;

    change = *a;
    *a = *b;
    *b = change;
}