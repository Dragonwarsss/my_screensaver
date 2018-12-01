/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** free_everything
*/

#include "window.h"
#include <stdlib.h>

static void free_screen3(sc3_t *win)
{
    for (int i = 0; i != 10; i += 1) {
        free(win->buffer[i]->pixel);
        free(win->buffer[i]);
        sfSprite_destroy(win->sprite[i]);
        sfTexture_destroy(win->texture[i]);
    }
}

void free_everything(screen_t *sc, sfRenderWindow *window)
{
    free_screen1(sc->sc1);
    free_screen2(sc->sc2);
    free_screen1(sc->sc3);
    free_screen1(sc->sc4);
    free_screen3(sc->sc5);
    free(sc);
    sfRenderWindow_destroy(window);
}
