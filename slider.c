/*
** EPITECH PROJECT, 2024
** slider.c
** File description:
** slider for paint project
*/

#include "my.h"

void setup(object *obj)
{
    sld_t *sld = malloc(sizeof(sld_t));

    sld->rayon = 30;
    sld->line = my_line(0, 620, 100, 5);
    sld->line2 = my_line(15, 520, 70, 3);
    sld->button = my_line(45, 515, 11, 11);
    obj->sld = sld;
}

int slider_change(object *obj, value *v)
{
    sfVector2f temp = {50, 515};

    if (v->m.x < 16) {
        temp.x = 15;
        obj->sld->rayon = 1;
        sfRectangleShape_setPosition(obj->sld->button, temp);
        return 1;
    }
    if (v->m.x > 85) {
        temp.x = 85;
        obj->sld->rayon = 75;
        sfRectangleShape_setPosition(obj->sld->button, temp);
        return 1;
    }
    temp.x = v->m.x;
    obj->sld->rayon = (v->m.x - 15);
    sfRectangleShape_setPosition(obj->sld->button, temp);
    return 1;
}

void all_destroy(value *v, object *obj, button **tab)
{
    for (int i = 0; i != 10; i++) {
        free(tab[i]);
    }
    free(tab);
    sfSprite_destroy(obj->brush);
    sfSprite_destroy(obj->eraser);
    sfSprite_destroy(obj->cat);
    sfRectangleShape_destroy(obj->line);
    sfRectangleShape_destroy(obj->line2);
    sfRectangleShape_destroy(obj->linev);
    sfRectangleShape_destroy(obj->menu);
    sfRectangleShape_destroy(obj->selec);
    sfRectangleShape_destroy(obj->task);
}

int save(value *v)
{
    sfImage_saveToFile(v->im->image, "save.png");
    return 0;
}
