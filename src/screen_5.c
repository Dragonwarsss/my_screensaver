/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** screen_5
*/

#include <stdlib.h>
#include "window.h"
#include "pixel.h"

static void check_disapeared(sfRenderStates *state)
{
    int x = state->transform.matrix[2];
    int y = state->transform.matrix[5];

    if (x > 1920 || x < -50) {
        state->transform.matrix[2] = rand() % 1920;
        state->transform.matrix[5] = -50;
    } else if (y > 1080 || y < -50) {
        state->transform.matrix[2] = rand() % 1920;
        state->transform.matrix[5] = -50;
    }
}

static sfVector2f change_speed(sfVector2f speed)
{
    int neg = rand() % 2;

    if (speed.x == 0) {
        speed.x = 5 ;
        speed.y = 0;
    } else {
        speed.x = 0;
        speed.y = 5;
    }
    if (neg == 1)
        speed.x *= -1;
    return (speed);
}

void screen_5(sfRenderWindow *window, screen_t *sc)
{
    sc3_t *win = sc->sc5;

    for (int i = 0; i != 10; i += 1) {
        sfRenderWindow_drawSprite(window, win->sprite[i], &win->state[i]);
        win->state[i].transform.matrix[2] += win->speed[i].x;
        win->state[i].transform.matrix[5] += win->speed[i].y;
        if ((rand() % 100) > 60)
            win->speed[i] = change_speed(win->speed[i]);
        check_disapeared(&win->state[i]);
    }
}

sc3_t *init_screen5(void)
{
    sc3_t *win = malloc(sizeof(sc3_t));

    if (!win)
        return (NULL);
    for (int i = 0; i != 10; i += 1) {
        win->sprite[i] = sfSprite_create();
        win->buffer[i] = create_buffer(50, 50);
        win->texture[i] = sfTexture_create(50, 50);
        win->buffer[i] = draw_square_buffer(win->buffer[i],
                                            50, (sfVector2f) {0, 0},
                                            rand_color());
        win->speed[i] = (sfVector2f) {0, 5};
        sfSprite_setTexture(win->sprite[i], win->texture[i], sfTrue);
        sfTexture_updateFromPixels(win->texture[i], win->buffer[i]->pixel,
                                   50, 50, 0, 0);
        win->state[i] = init_state();
        win->state[i].transform.matrix[5] = -50;
    }
    return (win);
}
