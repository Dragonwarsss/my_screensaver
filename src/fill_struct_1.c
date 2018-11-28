/*
** EPITECH PROJECT, 2018
** screensaver
** File description:
** fill_struct_1
*/

#include "window.h"
#include "pixel.h"
#include <stdlib.h>

void fill_struct_1(sc1_t *win)
{
    int size;

    for (int i = 0; i != 1000; i += 1) {
        size = rand() % 20 + 10;
        win->circle[i] = create_buffer(60, 60);
        win->c_sprite[i] = sfSprite_create();
        win->c_texture[i] = sfTexture_create(60, 60);
        win->speed[i] = (sfVector2f) {rand() % 6 - 3, rand() % 6 - 6};
        win->side[i] = rand() % 20 + 10;
        win->c_color[i] = rand_color();
        win->circle[i] = draw_circle_buffer(win->circle[i],
                                            size,
                                            (sfVector2f) {30, 30},
                                            win->c_color[i]);
        sfSprite_setTexture(win->c_sprite[i], win->c_texture[i], sfTrue);
        sfTexture_updateFromPixels(win->c_texture[i],
                                   win->circle[i]->pixel, 60, 60, 0, 0);
        win->state[i] = init_state();
        win->state[i].transform.matrix[5] += 1080;
    }
}
