/*
** EPITECH PROJECT, 2018
** CPool_Day13_2018
** File description:
** pixel.c
*/

#include "pixel.h"
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

framebuffer_t *set_clean_buffer(framebuffer_t *buffer)
{
    int i = 0;

    while (i != buffer->width * buffer->height * 4) {
        buffer->pixel[i ] = 0;
        buffer->pixel[i + 1] = 0;
        buffer->pixel[i + 2] = 0;
        buffer->pixel[i + 3] = 0;
        i += 4;
    }
    return (buffer);
}

framebuffer_t *create_buffer(int height, int width)
{
    framebuffer_t *buffer = malloc(sizeof(framebuffer_t));
    unsigned int buffer_size = height * width * 4;

    if (!buffer)
        return (NULL);
    buffer->pixel = malloc(sizeof(sfUint8) * buffer_size);
    for (unsigned int i = 0; i != buffer_size; i += 1)
        buffer->pixel[i] = 0;
    buffer->height = height;
    buffer->width = width;
    return (buffer);
}

framebuffer_t *set_pixel(framebuffer_t *buffer,
                         int x, int y, sfColor const color)
{
    int pos_pixel = (y * buffer->width + x) * 4;

    buffer->pixel[pos_pixel] = color.r;
    buffer->pixel[pos_pixel + 1] = color.g;
    buffer->pixel[pos_pixel + 2] = color.b;
    buffer->pixel[pos_pixel + 3] = color.a;
    return (buffer);
}

framebuffer_t *fill_buffer(framebuffer_t *buffer, sfColor const color)
{
    int i = 0;
    int j = 0;
    int pos_pixel = (i * buffer->width + j) * 4;

    for (i = 0; i < buffer->width; i += 1)
        for (j = 0; j < buffer->height; j += 1) {
            pos_pixel = (i * buffer->width + j) * 4;
            buffer->pixel[pos_pixel] = color.r;
            buffer->pixel[pos_pixel + 1] = color.g;
            buffer->pixel[pos_pixel + 2] = color.b;
            buffer->pixel[pos_pixel + 3] = color.a;
        }
    return (buffer);
}
