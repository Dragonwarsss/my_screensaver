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

void free_screen2(sc2_t *win)
{
    for (int j = 0; j != 100; j += 1) {
        sfSprite_destroy(win->c_sprite[j]);
        sfTexture_destroy(win->c_texture[j]);
        free(win->circle[j]->pixel);
        free(win->circle[j]);
    }
    free(win);
}

void screen_2(sfRenderWindow *window, sc2_t *win)
{
//    static int i = 0;
    int j;

    for (j = 0; j != 100; j += 1) {
        sfRenderWindow_drawSprite(window, win->c_sprite[j], NULL);
    }
}
