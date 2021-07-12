/*
** EPITECH PROJECT, 2020
** CPool_Day06
** File description:
** my_strcapitalize
*/

int can_you_change_in_capital(char *str, int i)
{
    int res = 0;

    if (str[i] <= 122 && str[i] >= 97)
        if (str[i - 1] < 48 || str[i - 1] > 57 && str[i - 1] < 65 ||
            str[i - 1] > 90 && str[i - 1] < 97 || str[i - 1] > 122)
            return 1;

    return -1;
}

char *my_strcapitalize(char *str)
{
    if (str[0] <= 122 && str[0] >= 97)
        str[0] = str[0] - 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] <= 90 && str[i] >= 65)
            str[i] = str[i] + 32;
        if (can_you_change_in_capital(str, i) == 1)
            str[i] = str[i] - 32;
    }
    return str;
}
