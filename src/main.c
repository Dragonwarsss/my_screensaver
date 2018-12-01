/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** main.c
*/

#include "pixel.h"
#include "window.h"
#include "my.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

void event_handler(sfEvent *event, sfRenderWindow *window, int *curr_win)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyRight && *curr_win != 5) {
            sfRenderWindow_clear(window, sfBlack);
            *curr_win += 1;
        }
        if (event->key.code == sfKeyLeft && *curr_win != 1) {
            sfRenderWindow_clear(window, sfBlack);
            *curr_win -= 1;
        }
    }
}

int main(int argc, char **argv, char **env)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    screen_t *sc;
    int curr_win = 1;
    int stat = 0;

    stat = print_usage(argc, argv, env);
    if (stat != 0)
        return (stat);
    curr_win = my_atoi(argv[1]);
    sc = init();
    window = sfRenderWindow_create(mode, "window", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 24);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(&event, window, &curr_win);
        select_screen(window, sc, curr_win);
    }
    free_everything(sc, window);
}
