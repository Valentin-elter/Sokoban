/*
** EPITECH PROJECT, 2019
** move
** File description:
** move the player
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../../include/mylist.h"

int check_up(char **map, pos *player)
{
    if(map[player->y - 1][player->x] == '#')
        return (0);
    if(map[player->y - 1][player->x] == 'X' &&
    map[player->y - 2][player->x] == '#')
        return (0);
    if(map[player->y - 1][player->x] == 'X' &&
    map[player->y - 2][player->x] == 'X')
        return (0);
    if(map[player->y - 1][player->x] == 'X' &&
    map[player->y - 2][player->x] == ' ')
        map[player->y - 2][player->x] = 'X';
    if(map[player->y - 1][player->x] == 'X' &&
    map[player->y - 2][player->x] == 'O')
        map[player->y - 2][player->x] = 'X';
    map[player->y][player->x] = player->stor;
    if(map[player->y - 1][player->x] == 'O')
        player->stor = 'O';
    else
        player->stor = ' ';
    map[player->y - 1][player->x] = 'P';
    return (1);
}

int check_down(char **map, pos *player)
{
    if(map[player->y + 1][player->x] == '#')
        return (0);
    if(map[player->y + 1][player->x] == 'X' &&
    map[player->y + 2][player->x] == '#')
        return (0);
    if(map[player->y + 1][player->x] == 'X' &&
    map[player->y + 2][player->x] == 'X')
        return (0);
    if(map[player->y + 1][player->x] == 'X' &&
    map[player->y + 2][player->x] == ' ')
        map[player->y + 2][player->x] = 'X';
    if(map[player->y + 1][player->x] == 'X' &&
    map[player->y + 2][player->x] == 'O')
        map[player->y + 2][player->x] = 'X';
    map[player->y][player->x] = player->stor;
    if(map[player->y + 1][player->x] == 'O')
        player->stor = 'O';
    else
        player->stor = ' ';
    map[player->y + 1][player->x] = 'P';
    return (1);
}

int check_left(char **map, pos *player)
{
    if(map[player->y][player->x - 1] == '#')
        return (0);
    if(map[player->y][player->x - 1] == 'X' &&
    map[player->y][player->x - 2] == '#')
        return (0);
    if(map[player->y][player->x - 1] == 'X' &&
    map[player->y][player->x - 2] == 'X')
        return (0);
    if(map[player->y][player->x - 1] == 'X' &&
    map[player->y][player->x - 2] == ' ')
        map[player->y][player->x - 2] = 'X';
    if(map[player->y][player->x - 1] == 'X' &&
    map[player->y][player->x - 2] == 'O')
        map[player->y][player->x - 2] = 'X';
    map[player->y][player->x] = player->stor;
    if(map[player->y][player->x - 1] == 'O')
        player->stor = 'O';
    else
        player->stor = ' ';
    map[player->y][player->x - 1] = 'P';
    return (1);
}

int check_right(char **map, pos *player)
{
    if(map[player->y][player->x + 1] == '#')
        return (0);
    if(map[player->y][player->x + 1] == 'X' &&
    map[player->y][player->x + 2] == '#')
        return (0);
    if(map[player->y][player->x + 1] == 'X' &&
    map[player->y][player->x + 2] == 'X')
        return (0);
    if(map[player->y][player->x + 1] == 'X' &&
    map[player->y][player->x + 2] == ' ')
        map[player->y][player->x + 2] = 'X';
    if(map[player->y][player->x + 1] == 'X' &&
    map[player->y][player->x + 2] == 'O')
        map[player->y][player->x + 2] = 'X';
    map[player->y][player->x] = player->stor;
    if(map[player->y][player->x + 1] == 'O')
        player->stor = 'O';
    else
        player->stor = ' ';
    map[player->y][player->x + 1] = 'P';
    return (1);
}

void free_all(g_map *map)
{
    free_map(map->map);
    free_map(map->reset);
    free(map);
    endwin();
}