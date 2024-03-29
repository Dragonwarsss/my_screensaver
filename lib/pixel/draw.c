/*
** EPITECH PROJECT, 2018
** libpixel
** File description:
** draw objects
*/

#include "pixel.h"
#include <math.h>

framebuffer_t *draw_square_buffer(framebuffer_t *buffer,
                                  int const size,
                                  sfVector2f const pos, sfColor const color)
{
    int i = pos.y;
    int j = pos.x;
    int pos_pixel = (i * buffer->width + j) * 4;

    for (; i < pos.y + size; i += 1)
        for (j = pos.x; j < pos.x + size; j += 1) {
            pos_pixel = (i * buffer->width + j) * 4;
            buffer->pixel[pos_pixel] = color.r;
            buffer->pixel[pos_pixel + 1] = color.g;
            buffer->pixel[pos_pixel + 2] = color.b;
            buffer->pixel[pos_pixel + 3] = color.a;
        }
    return (buffer);
}

framebuffer_t *draw_circle_buffer(framebuffer_t *buffer, int const size,
                                  sfVector2f const pos, sfColor const color)
{
    int i = pos.y - size;
    int j = pos.x - size;
    int pos_pixel = (i * buffer->width + j) * 4;

    for (; i <= pos.y + size; i += 1) {
        for (j = pos.x - size; j <= pos.x + size; j += 1) {
            pos_pixel = (i * buffer->width + j) * 4;
            if (curr_point(pos, j, i) <= size) {
                pos_pixel = (i * buffer->width + j) * 4;
                buffer->pixel[pos_pixel] = color.r;
                buffer->pixel[pos_pixel + 1] = color.g;
                buffer->pixel[pos_pixel + 2] = color.b;
                buffer->pixel[pos_pixel + 3] = color.a;
            }
        }
    }
    return (buffer);
}

framebuffer_t *draw_arc_buffer(framebuffer_t *buffer, int size,
                               int lenght, sfVector2f const pos,
                               sfColor const color)
{
    int i = pos.y - size;
    int j = pos.x - size;
    int l = 0;

    for (; i < pos.y + size; i += 1) {
        for (j = pos.x - size; j <= pos.x + size; j += 1) {
            if (curr_point(pos, j, i) == size) {
                draw_circle_buffer(buffer, 15, (sfVector2f) {j, i}, color);
            }
        }
        l += 1;
        if (l == lenght)
            break;
    }
    return (buffer);
}

int curr_point(sfVector2f const ref, int const x, int const y)
{
    int res = pow(x - ref.x, 2) + pow(y - ref.y, 2);

    res = sqrt(res);
    if (res < 0)
        res *= -1;
    return (res);
}
