/*
** EPITECH PROJECT, 2018
** screensaver
** File description:
** init.c
*/

#include "pixel.h"
#include "window.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <time.h>
#include <stdlib.h>

sfColor rand_color()
{
    sfColor color;

    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;
    color.a = 100;
    return (color);
}

sc2_t *init_screen2(void)
{
    sc2_t *win = malloc(sizeof(sc2_t));
    int i = 0;

    for (; i != 100; i += 1) {
        win->circle[i] = create_buffer(500, 500);
        win->c_sprite[i] = sfSprite_create();
        win->c_texture[i] = sfTexture_create(500, 500);
        win->pos[i] = (sfVector2f) {rand() % 1620,rand() % 1080};
        win->c_color[i] = rand_color();
        win->circle[i] = draw_arc_buffer(win->circle[i], 200, 40, (sfVector2f) {250, 250}, win->c_color[i]);
        sfSprite_setTexture(win->c_sprite[i], win->c_texture[i], sfTrue);
        sfTexture_updateFromPixels(win->c_texture[i], win->circle[i]->pixel, 500, 500, 0, 0);
        sfSprite_setPosition(win->c_sprite[i], win->pos[i]);
    }
    return (win);
}

sc1_t *init_screen1(void)
{
    sc1_t *win = malloc(sizeof(sc1_t));
    int size = 0;
    int i = 0;

    srand(time(NULL));
    for (; i != 1000; i += 1) {
        size = rand() % 20 + 10;
        win->circle[i] = create_buffer(60, 60);
        win->c_sprite[i] = sfSprite_create();
        win->c_texture[i] = sfTexture_create(60, 60);
        win->pos[i] = (sfVector2f) {rand() % 1920, rand() % 1080 + 1080};
        win->speed[i] = (sfVector2f) {rand() % 6 - 3, rand() % 6 - 6};
        win->side[i] = rand() % 20 + 10;
        win->c_color[i] = rand_color();
        win->circle[i] = draw_circle_buffer(win->circle[i], size, (sfVector2f) {30, 30}, win->c_color[i]);
        sfSprite_setTexture(win->c_sprite[i], win->c_texture[i], sfTrue);
        sfTexture_updateFromPixels(win->c_texture[i], win->circle[i]->pixel, 60, 60, 0, 0);
        sfSprite_setPosition(win->c_sprite[i], win->pos[i]);
    }
    return (win);
}