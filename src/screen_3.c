/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** bubble screen
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "pixel.h"
#include "window.h"

void screen_3(sfRenderWindow *window, sc1_t *win)
{
    static int i = 0;
    int j;

    sfRenderWindow_clear(window, sfBlack);
    for (j = 0; j != 1000; j += 1) {
        sfRenderWindow_drawSprite(window, win->c_sprite[j], &win->state[j]);
        win->state[j].transform.matrix[2] += win->speed[j].x;
        win->state[j].transform.matrix[5] += win->speed[j].y;
        if (i == win->side[j])
            win->speed[j].x *= -1;
    }
    i += 1;
    if (i == 30)
        i = 0;
    for (j = 0; j != 1000; j += 1) {
        if (win->state[j].transform.matrix[5] < -50) {
        win->pos[j].y = rand() % 1080 + 1080;
            win->state[j].transform.matrix[5] = rand() % 1080 + 1080;
}
    }
}
