/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "pixel.h"
#include "window.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

void event_handler(sfEvent *event, sfRenderWindow *window, int *curr_win)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyRight)
            *curr_win = 0;
        if (event->key.code == sfKeyLeft)
            *curr_win = 1;
    }
}

int main(int argc, char **argv, char **env)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    sc1_t *win;
    sc2_t *win_2;
    int curr_win = 1;
    int stat = 0;

    stat = print_usage(argc, argv, env);
    if (stat != 0)
        return (stat);
    win = init_screen1();
    win_2 = init_screen2();
    window = sfRenderWindow_create(mode, "window", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 24);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(&event, window, &curr_win);
/*        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            for (int j = 0; j != 1000; j += 1) {
                free(win->circle[j]->pixel);
                free(win->circle[j]);
                sfSprite_destroy(win->c_sprite[j]);
                sfTexture_destroy(win->c_texture[j]);
            }
            free(win);
            win = init();
            }*/
        if (curr_win == 1)
            screen_1(window, win);
        if (curr_win == 0)
            screen_2(window, win_2);
    }
    free_screen1(win);
    free_screen2(win_2);
    sfRenderWindow_destroy(window);
}
