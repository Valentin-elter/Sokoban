/*
** EPITECH PROJECT, 2019
** Main
** File description:
** The main game
*/

#include "include/mylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ncurses.h>

void description_game(void)
{
    my_putstr("USAGE\n        ./my_sokoban map\nDESCRIPTION\n");
    my_putstr("        map  file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n             ‘P’ for the player,");
    my_putstr("‘X’ for boxes and ‘O’ for storage locations.\n");
}

int checkfile(char const *filepath)
{
    int file = open(filepath, O_RDONLY);
    struct stat inf_file;
    char *buff;

    if (file == -1)
        return (0);
    stat(filepath, &inf_file);
    buff = malloc(inf_file.st_size + 3);
    read(file, buff, inf_file.st_size);
    close(file);
    for (int i = 0; buff[i] != '\0'; ++i)
        if(buff[i] != '\n' && buff[i] != '\0' && buff[i] != 'X' &&
        buff[i] != 'O' && buff[i] != 'P' && buff[i] != ' ' && buff[i] != '#')
            return (0);
    return (1);
}

void fill_map(g_map* map, char **argv)
{
    map->map = my_array_map(argv[1]);
    map->reset = my_array_map(argv[1]);
    map->nb_rows = count_rows(argv[1]);
    map->len = my_strlen(map->map[0]) / 2;
}

int sokoban(char **argv)
{
    g_map *map = malloc(sizeof(*map));
    pos *player = malloc(sizeof(*player));
    int end = 0;

    fill_map(map, argv);
    begin(map->map, map->nb_rows, map->len, player);
    while(1) {
        clear();
        print_map(map->map, map->nb_rows, map->len);
        end = player_move(map, player);
        if (end < 2) {
            for (int i = 0; i < 10000; i++)
            for (int y = 0; y < 250000; y++);
            break;
        }
        if (end == 3)
            reset_map(map->map, map->reset);
        replace_box(map->map, map->reset);
    }
    free_all(map);
    return (end);
}

int main(int argc, char **argv)
{
    int end = 0;

    if (argc != 2)
        return (0);
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        description_game();
        return (0);
    }
    if (checkfile(argv[1]) == 0)
        return (0);
    end = sokoban(argv);
    return (end);
}