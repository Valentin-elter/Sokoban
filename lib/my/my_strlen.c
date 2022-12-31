/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
**
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
