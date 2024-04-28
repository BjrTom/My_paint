/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** setup_sprite
*/

#include "my.h"

static sfRectangleShape *my_menu(void)
{
    sfVector2f size = {200, 100};
    sfVector2f pos = {110, 0};
    sfRectangleShape *menu = sfRectangleShape_create();

    sfRectangleShape_setPosition(menu, pos);
    sfRectangleShape_setSize(menu, size);
    sfRectangleShape_setFillColor(menu, (sfColor){255, 255, 255, 150});
    return menu;
}

static sfSprite *my_save(value *v)
{
    sfVector2f scale = {0.15, 0.15};
    sfVector2f pos = {10, 110};
    sfTexture *save = sfTexture_createFromFile("./src/save.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, save, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(v->window, sprite, NULL);
    return sprite;
}

sfRectangleShape *my_line(int x, int y, int p, int j)
{
    sfVector2f size = {p, j};
    sfVector2f pos = {x, y};
    sfRectangleShape *line = sfRectangleShape_create();

    sfRectangleShape_setPosition(line, pos);
    sfRectangleShape_setSize(line, size);
    sfRectangleShape_setFillColor(line, sfBlack);
    return line;
}

static sfRectangleShape *my_task(void)
{
    sfVector2f size = {1720, 800};
    sfVector2f pos = {100, 100};
    sfRectangleShape *rec = sfRectangleShape_create();

    sfRectangleShape_setPosition(rec, pos);
    sfRectangleShape_setSize(rec, size);
    sfRectangleShape_setFillColor(rec, sfTransparent);
    sfRectangleShape_setOutlineColor(rec, (sfColor){177, 177, 177, 255});
    sfRectangleShape_setOutlineThickness(rec, 100);
    return rec;
}

sfRectangleShape *my_selec(value *v)
{
    sfVector2f size = {30, 30};
    sfRectangleShape *selec = sfRectangleShape_create();

    sfRectangleShape_setOutlineColor(selec, sfBlack);
    sfRectangleShape_setOutlineThickness(selec, 2);
    sfRectangleShape_setFillColor(selec, sfTransparent);
    sfRectangleShape_setPosition(selec, v->selecpos);
    sfRectangleShape_setSize(selec, size);
    sfRenderWindow_drawRectangleShape(v->window, selec, NULL);
    return selec;
}

static sfSprite *my_brush(value *v)
{
    sfVector2f scale = {0.06, 0.06};
    sfVector2f pos = {130, 15};
    sfTexture *brush = sfTexture_createFromFile("./src/brush.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, brush, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(v->window, sprite, NULL);
    return sprite;
}

static sfSprite *my_eraser(value *v)
{
    sfVector2f scale = {0.06, 0.06};
    sfVector2f pos = {220, 15};
    sfTexture *eraser = sfTexture_createFromFile("./src/eraser.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, eraser, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(v->window, sprite, NULL);
    return sprite;
}

static sfSprite *my_cat(value *v)
{
    sfVector2f scale = {0.04, 0.04};
    sfVector2f pos = {0, 0};
    sfTexture *cat = sfTexture_createFromFile("./src/cat.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, cat, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(v->window, sprite, NULL);
    return sprite;
}

void startup(value *v, object *obj)
{
    obj->task = my_task();
    obj->line = my_line(0, 200, 100, 5);
    obj->line2 = my_line(0, 420, 100, 5);
    obj->linev = my_line(100, 0, 5, 100);
    obj->selec = my_selec(v);
    obj->cat = my_cat(v);
    obj->menu = my_menu();
    obj->brush = my_brush(v);
    obj->eraser = my_eraser(v);
    obj->save = my_save(v);
    setup(obj);
}
