/*
** EPITECH PROJECT, 2019
** conditional
** File description:
** fonctions for special case
*/

#include "../../include/mylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ncurses.h>

int resize_window(char **map, int nb_rows, int len)
{
    while (LINES < nb_rows || COLS < len) {
        clear();
        printw("window need to be bigger");
        if (getch() != 410) {
            free_map(map);
            endwin();
            return (1);
        }
    }
}

void begin(char **map, int nb_rows, int len, pos *player)
{
    initscr();
    cbreak();
    keypad(stdscr,TRUE);
    noecho();
    resize_window(map, nb_rows, len);
    player->stor = ' ';
}

void print_map(char **map, int nb_rows, int len)
{
    for (int i = 0; map[i] != NULL; i++)
        mvprintw((LINES / 2) + i - (nb_rows / 2),
                 COLS / 2 - len, "%s\n", map[i]);
    refresh();
}

void reset_map(char **map, char **reset)
{
    int i = 0;

    for (int y = 0; map[y] != NULL; ++y) {
        for (int i = 0; map[y][i] != '\0'; ++i)
            map[y][i] = reset[y][i];
    }
}

void replace_box(char **map, char **reset)
{
    for (int y = 0; map[y] != NULL; ++y)
        for (int i = 0; map[y][i] != '\0'; ++i)
            if (reset[y][i] == 'O' && map[y][i] == ' ')
                map[y][i] = reset[y][i];
}