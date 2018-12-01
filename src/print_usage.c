/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** print usage
*/

#include "my.h"
#include <stdlib.h>

static void print_desc(void)
{
    my_printf("1: virus filling your screen by climbing\n"
              "2: windscreen wiper getting mad\n"
              "3: some bubbles flying\n"
              "4: should have been fire but it's more like lemonade's bubble"
              "5: little snakes strolls the screen\n");
}

static void print_help(void)
{
    my_printf("animation rendering in a CSFML window\n\nUSAGE\n"
              "  ./my_screensaver\t[OPTIONS] animation_id\n"
              "  animation_id\t\tID of the animation to process "
              "(between 1 and 3).\n\n"
              "OPTIONS\n -d\t\t\tprint the description of all the "
              "animations and quit.\n -h\t\t\tprint the usage and quit.\n"
              "\nUSER_INTERACTIONS\n  LEFT_ARROW\t\tswitch to the previous."
              "animation\n  RIGHT_ARROW\t\tswitch to the next animation.\n"
        );
}

int print_usage(int ac, char **av, char **env)
{
    if (env[5] == NULL)
        return (84);
    if (ac != 2)
        return (1);
    if (my_strcomp(av[1], "-h")) {
        print_help();
        return (1);
    } else if (my_strcomp(av[1], "-d")) {
        print_desc();
        return (1);
    }
    return (0);
}
