/*
** EPITECH PROJECT, 2019
** move_player
** File description:
** move the player
*/

#include "../../include/mylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ncurses.h>

int player_move(g_map *map, pos *player)
{
    int ch;
    int end;

    ch = getch();
    get_pos(player, map->map);
    move_play(map->map, player, ch);
    if (ch == ' ')
        return (3);
    end = finish(map->map, map->reset);
    print_map(map->map, map->nb_rows, map->len);
    return (end);
}

void get_pos(pos *player, char **map)
{
    for (int a = 0; map[a] != NULL; ++a)
        for (int b = 0; map[a][b] != '\n' && map[a][b] != '\0'; ++b)
            if (map[a][b] == 'P') {
                player->x = b;
                player->y = a;
                break;
            }
}

int check_box(char **map, int y, int i)
{
    if (map[y + 1][i] == '#' || map[y + 1][i] == 'X') {
        if (map[y][i + 1] == '#' || map[y][i + 1] == 'X')
            return (0);
        if (map[y][i - 1] == '#' || map[y][i - 1] == 'X')
            return (0);
    }
    if (map[y - 1][i] == '#' || map[y - 1][i] == 'X') {
        if (map[y][i + 1] == '#' || map[y][i + 1] == 'X')
            return (0);
        if (map[y][i - 1] == '#' || map[y][i - 1] == 'X')
            return (0);
    }
    return (1);
}

void move_play(char **map, pos *player, int ch)
{
    if (ch == KEY_UP)
        check_up(map, player);
    if (ch == KEY_LEFT)
        check_left(map, player);
    if (ch == KEY_RIGHT)
        check_right(map, player);
    if (ch == KEY_DOWN)
        check_down(map, player);
}

int finish(char **map, char **reset)
{
    int check = 0;
    int storage = 0;
    int stored = 0;

    for (int y = 0; map[y] != NULL; ++y)
        for (int i = 0; map[y][i] != '\0'; ++i) {
            if (map[y][i] == 'X')
                check += check_box(map, y, i);
            if (map[y][i] == 'X' && reset[y][i] == 'O')
                ++stored;
            if (reset[y][i] == 'O')
                ++storage;
        }
    if (stored == storage)
        return (0);
    if (check == 0)
        return (1);
    return (2);
}