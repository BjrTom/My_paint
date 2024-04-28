/*
** EPITECH PROJECT, 2024
** circle_draw.c
** File description:
** circle draw function for paint
*/

#include "my.h"

image_t *create_new_image(int argc, char **argv)
{
    image_t *im = malloc(sizeof(image_t));

    if (argc == 2) {
        im->image = sfImage_createFromFile(argv[1]);
        if (im->image == NULL)
            im->image = sfImage_createFromColor(1920, 1080, sfWhite);
    } else
        im->image = sfImage_createFromColor(1920, 1080, sfWhite);
    im->sprite = sfSprite_create();
    im->texture = sfTexture_createFromImage(im->image, NULL);
    sfSprite_setTexture(im->sprite, im->texture, sfTrue);
    return im;
}

void circle_ring_draw(image_t *im, value *v, int x, int y)
{
    sfImage_setPixel(im->image, (v->m.x + x), (v->m.y + y), v->selec_color);
    sfImage_setPixel(im->image, (v->m.x + x), (v->m.y - y), v->selec_color);
    sfImage_setPixel(im->image, (v->m.x - x), (v->m.y + y), v->selec_color);
    sfImage_setPixel(im->image, (v->m.x - x), (v->m.y - y), v->selec_color);
    sfImage_setPixel(im->image, (v->m.x + y), (v->m.y + x), v->selec_color);
    sfImage_setPixel(im->image, (v->m.x + y), (v->m.y - x), v->selec_color);
    sfImage_setPixel(im->image, (v->m.x - y), (v->m.y + x), v->selec_color);
    sfImage_setPixel(im->image, (v->m.x - y), (v->m.y - x), v->selec_color);
}

void circle_draw(value *v, image_t *im, int const rayon)
{
    int x = 0;
    int y = rayon;
    int d = 3 - 2 * rayon;

    circle_ring_draw(im, v, x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else
            d = d + 4 * x + 6;
        circle_ring_draw(im, v, x, y);
    }
}
