/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <SFML/Graphics.h>
#include "pixel.h"

#ifndef WINDOW_STRUCT
#define WINDOW_STRUCT

typedef struct s_sc1 sc1_t;
typedef struct s_sc2 sc2_t;
typedef struct s_sc3 sc3_t;
typedef struct s_screen screen_t;

typedef struct s_screentab screentab_t;

struct s_screentab {
    int ref;
    void (*ptr)(sfRenderWindow *, screen_t *);
};

struct s_sc3 {
    framebuffer_t *buffer[10];
    sfSprite *sprite[10];
    sfTexture *texture[10];
    sfColor color[10];
    sfRenderStates state[10];
    sfVector2f speed[10];
};

struct s_sc2 {
    framebuffer_t *circle[100];
    sfSprite *c_sprite[100];
    sfTexture *c_texture[100];
    sfColor c_color[100];
    sfRenderStates state[100];
};

struct s_sc1 {
    framebuffer_t *circle[1000];
    sfSprite *c_sprite[1000];
    sfTexture *c_texture[1000];
    sfVector2f pos[1000];
    sfColor c_color[1000];
    sfVector2f speed[1000];
    int side[1000];
    sfRenderStates state[1000];
};

struct s_screen {
    sc1_t *sc1;
    sc2_t *sc2;
    sc1_t *sc3;
    sc1_t *sc4;
    sc3_t *sc5;
};

sc1_t *saved(void);
sfRenderStates init_state(void);
sfColor rand_color_fire(void);
screen_t *init(void);
void fill_struct_1(sc1_t *win);
sc1_t *init_screen1(void);
sc2_t *init_screen2(void);
sc1_t *init_screen4(void);
sc3_t *init_screen5(void);

sfColor rand_color(void);

void select_screen(sfRenderWindow *window, screen_t *sc, int curr_win);

void screen_1(sfRenderWindow *window, screen_t *sc);
void screen_2(sfRenderWindow *window, screen_t *sc);
void screen_3(sfRenderWindow *window, screen_t *sc);
void screen_4(sfRenderWindow *window, screen_t *sc);
void screen_5(sfRenderWindow *window, screen_t *sc);

void fade_color(sc1_t *win);

int print_usage(int ac, char **av, char **env);
void free_everything(screen_t *sc, sfRenderWindow *window);
void free_screen1(sc1_t *win);
void free_screen2(sc2_t *win);

#endif
