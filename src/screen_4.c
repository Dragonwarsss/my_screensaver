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

void fade_color(sc1_t *win)
{
    for (int i = 0; i != 1000; i += 1) {
        win->c_color[i].a -= 5;
        if (win->c_color[i].a == 0)
            win->c_color[i].a = 200;
    }
}

void screen_4(sfRenderWindow *window, sc1_t *win)
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
            win->state[j].transform.matrix[5] = rand() % 600 + 1680;
        }
    }
    fade_color(win);
}

sfColor rand_color_fire(void)
{
    sfColor color;

    color.r = 244;
    color.g = rand() % 134 + 66;
    color.b = 66;
    color.a = 150;
    return (color);
}

sc1_t *init_screen4(void)
{
    sc1_t *win = malloc(sizeof(sc1_t));
    int size = 0;
    int i = 0;

    srand(time(NULL));
    for (; i != 1000; i += 1) {
        size = rand() % 5 + 10;
        win->circle[i] = create_buffer(60, 60);
        win->c_sprite[i] = sfSprite_create();
        win->c_texture[i] = sfTexture_create(60, 60);
        win->speed[i] = (sfVector2f) {rand() % 6 - 3, rand() % 18 - 18};
        win->side[i] = rand() % 5 + 10;
        win->c_color[i] = rand_color_fire();
        win->circle[i] = draw_circle_buffer(win->circle[i], size, (sfVector2f) {30, 30}, win->c_color[i]);
        sfSprite_setTexture(win->c_sprite[i], win->c_texture[i], sfTrue);
        sfTexture_updateFromPixels(win->c_texture[i], win->circle[i]->pixel, 60, 60, 0, 0);
        win->state[i] = init_state();
        win->state[i].transform.matrix[2] = rand() % 600 + 600;
        win->state[i].transform.matrix[5] = rand() % 1080;

    }
    return (win);
}
