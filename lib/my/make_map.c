/*
** EPITECH PROJECT, 2019
** make_map
** File description:
** make the map
*/

#include "../../include/mylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ncurses.h>

int count_lines(char const *str)
{
    int lines = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            ++lines;
    return (lines + 1);
}

void fill_array(char *buff, char **map, int nb_lines)
{
    int a = 0;
    int i = 0;
    int b = 0;

    for (a = 0; a < nb_lines; a++, i++)
        for (b = 0; buff[i] != '\n' && buff[i] != '\0'; i++, b++)
            map[a][b] = buff[i];
    map[a - 1] = NULL;
}

char **my_array_map(char const *filepath)
{
    int file = open(filepath, O_RDONLY);
    struct stat inf_file;
    char *buff;
    char **map;
    int nb_lines;

    stat(filepath, &inf_file);
    buff = malloc(inf_file.st_size + 3);
    read(file, buff, inf_file.st_size);
    close(file);
    nb_lines = count_lines(buff);
    map = malloc((nb_lines + 1) * sizeof(char*));
    for (int i = 0; i < nb_lines; i++)
        map[i] = malloc(inf_file.st_size);
    fill_array(buff, map, nb_lines);
    free(buff);
    return (map);
}

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

int count_rows(char const *filepath)
{
    int file = open(filepath, O_RDONLY);
    struct stat inf_file;
    char *buff;
    int nb_lines;

    stat(filepath, &inf_file);
    buff = malloc(inf_file.st_size + 3);
    read(file, buff, inf_file.st_size);
    close(file);
    nb_lines = count_lines(buff);
    free(buff);
    return (nb_lines);
}