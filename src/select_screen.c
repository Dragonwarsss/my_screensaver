/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** select_screen.c
*/

#include "window.h"

void select_screen(sfRenderWindow *window, screen_t *sc, int curr_win)
{
    if (curr_win == 1)
        screen_1(window, sc);
    if (curr_win == 2)
        screen_2(window, sc);
    if (curr_win == 3)
        screen_3(window, sc);
    if (curr_win == 4)
        screen_4(window, sc);
    if (curr_win == 5)
        screen_5(window, sc);
}
