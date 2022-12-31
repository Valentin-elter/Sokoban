/*
** EPITECH PROJECT, 2019
** mylist
** File description:
** header
*/

typedef struct pos
{
    int x;
    int y;
    char stor;
} pos;

typedef struct g_map
{
    char **map;
    char **reset;
    int nb_rows;
    int len;
} g_map;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int check_up(char **map, pos *player);
int check_down(char **map, pos *player);
int check_left(char **map, pos *player);
int check_right(char **map, pos *player);
int count_lines(char const *str);
void fill_array(char *buff, char **map, int nb_lines);
char **my_array_map(char const *filepath);
void free_map(char **map);
int count_rows(char const *filepath);
int player_move(g_map *map, pos *player);
void get_pos(pos *player, char **map);
int check_box(char **map, int y, int i);
void move_play(char **map, pos *player, int ch);
int resize_window(char **map, int nb_rows, int len);
void begin(char **map, int nb_rows, int len, pos *player);
void print_map(char **map, int nb_rows, int len);
void reset_map(char **map, char **reset);
int finish(char **map, char **reset);
void replace_box(char **map, char **reset);
void free_all(g_map *map);