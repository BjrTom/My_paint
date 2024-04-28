/*
** EPITECH PROJECT, 2024
** All_code
** File description:
** main
*/

#include "my.h"

void init_button(sfVector2f pos, sfVector2f size, button *mybutt, sfColor co)
{
    mybutt->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(mybutt->rect, pos);
    sfRectangleShape_setSize(mybutt->rect, size);
    sfRectangleShape_setFillColor(mybutt->rect, co);
    return;
}

static sfColor *create_tab(value *v)
{
    sfColor color_tab2[] = {
        sfBlue, sfBlack, sfRed, sfCyan, sfGreen, sfMagenta, sfYellow,
        sfWhite, (sfColor){255, 143, 0, 255}, (sfColor){242, 124, 221, 255}
    };

    v->c_tab = malloc(sizeof(sfColor) * 10);
    for (int i = 0; i != 10; i++)
        v->c_tab[i] = color_tab2[i];
}

static void setup_array(button **tab, value *v, int x, int y)
{
    sfVector2f size = {30, 30};
    sfVector2f pos = {x, y};

    v->nb_color = 10;
    create_tab(v);
    for (int i = 0; i != v->nb_color; i++) {
        tab[i] = malloc(sizeof(button));
        pos.x = x;
        pos.y = y;
        tab[i]->color = v->c_tab[i];
        tab[i]->pos = pos;
        tab[i]->size = size;
        init_button(tab[i]->pos, tab[i]->size, tab[i], v->c_tab[i]);
        y += 40;
        if (i == 4) {
            x += 40;
            y = 220;
        }
    }
}

void drawing_update(image_t *im, value *info, object *obj)
{
    for (int i = 1; i < obj->sld->rayon; ++i)
        circle_draw(info, im, i);
    sfTexture_updateFromImage(im->texture, im->image, 0, 0);
}

void my_color(button **tab, value *v, object *obj)
{
    int x1;
    int x2;
    int y1;
    int y2;

    for (int i = 0; i != 10; i++) {
        x1 = tab[i]->pos.x;
        x2 = tab[i]->pos.x + 30;
        y1 = tab[i]->pos.y;
        y2 = tab[i]->pos.y + 30;
        if (v->m.x >= x1 && v->m.x <= x2 && v->m.y >= y1 && v->m.y <= y2) {
                sfRectangleShape_setPosition(obj->selec, tab[i]->pos);
                v->selec_color = tab[i]->color;
        }
    }
}

static void in_paint(value *v, object *obj)
{
        if (v->m.x >= 10 && v->m.x <= 50 && v->m.y >= 110 && v->m.y <= 160 &&
            v->event.type == sfEvtMouseButtonPressed)
            save(v);
    if (v->m.x >= 100 && v->m.x <= 1820 && v->m.y >= 100 && v->m.y <= 980 &&
        v->state == false && v->event.type == sfEvtMouseButtonPressed)
        v->state = true;
    if (v->event.type == sfEvtMouseButtonReleased)
        v->state = false;
    if (v->state == true)
        if (v->m.x > 100 && v->m.x < 1820 &&
            v->m.y > 100 && v->m.y < 980)
            drawing_update(v->im, v, obj);
        else
            v->state = false;
    if (v->m.x >= 0 && v->m.x <= 100 && v->m.y >= 420 && v->m.y <= 620 &&
        v->event.type == sfEvtMouseButtonPressed)
        slider_change(obj, v);
}

static void in_state(button **tab, value *v, object *obj)
{
    v->m = sfMouse_getPosition((sfWindow *)v->window);
    if (v->event.type == sfEvtMouseButtonPressed) {
        if (v->m.x >= 3 && v->m.x <= 98 && v->m.y >= 208 && v->m.y <= 417) {
            my_color(tab, v, obj);
            return;
        }
        if (v->m.x >= 220 && v->m.x <= 270 && v->m.y >= 15 && v->m.y <= 80 &&
            obj->state == true) {
            v->old_color = v->selec_color;
            v->selec_color = sfWhite;
            }
        if (v->m.x >= 130 && v->m.x <= 180 && v->m.y >= 15 && v->m.y <= 80 &&
            obj->state == true)
            v->selec_color = v->old_color;
    }
    if (v->m.x >= 0 && v->m.x <= 100 && v->m.y >= 0 && v->m.y <= 100)
        obj->state = true;
    else if (v->m.x > 0 && v->m.x > 300 || v->m.y > 0 && v->m.y > 100)
        obj->state = false;
    in_paint(v, obj);
}

void all_draw(value *v, object *obj, button **tab)
{
    sfRenderWindow_drawSprite(v->window, v->im->sprite, NULL);
    sfRenderWindow_drawRectangleShape(v->window, obj->task, NULL);
    sfRenderWindow_drawRectangleShape(v->window, obj->line, NULL);
    sfRenderWindow_drawRectangleShape(v->window, obj->line2, NULL);
    sfRenderWindow_drawRectangleShape(v->window, obj->linev, NULL);
    if (obj->state == true) {
        sfRenderWindow_drawRectangleShape(v->window, obj->menu, NULL);
        sfRenderWindow_drawSprite(v->window, obj->eraser, NULL);
        sfRenderWindow_drawSprite(v->window, obj->brush, NULL);
    }
    for (int i = 0; i != v->nb_color; i++)
        sfRenderWindow_drawRectangleShape(v->window, tab[i]->rect, NULL);
    sfRenderWindow_drawSprite(v->window, obj->cat, NULL);
    sfRenderWindow_drawSprite(v->window, obj->save, NULL);
    sfRenderWindow_drawRectangleShape(v->window, obj->selec, NULL);
    sfRenderWindow_drawRectangleShape(v->window, obj->sld->button, NULL);
    sfRenderWindow_drawRectangleShape(v->window, obj->sld->line2, NULL);
    sfRenderWindow_drawRectangleShape(v->window, obj->sld->line, NULL);
}

static void big_loop(value *v, object *obj, button **tab)
{
    while (sfRenderWindow_isOpen(v->window)) {
        sfRenderWindow_clear(v->window, sfWhite);
        all_draw(v, obj, tab);
        while (sfRenderWindow_pollEvent(v->window, &v->event)) {
            in_state(tab, v, obj);
        }
        sfRenderWindow_display(v->window);
        if (v->event.type == sfEvtClosed) {
            sfRenderWindow_close(v->window);
        }
    }
}

int main(int argc, char **argv)
{
    button **tab = malloc(sizeof(button *) * 10);
    value v;
    object obj;
    image_t *im = create_new_image(argc, argv);
    sfVideoMode mode = {1920, 1080, 32};
    int n = 0;

    v.old_color = sfWhite;
    obj.state = false;
    v.im = im;
    v.state = false;
    setup_array(tab, &v, 15, 220);
    v.selecpos = tab[7]->pos;
    v.window = sfRenderWindow_create(mode, "pipou", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(v.window, 60);
    if (!v.window)
        return EXIT_FAILURE;
    startup(&v, &obj);
    big_loop(&v, &obj, tab);
    all_destroy(&v, &obj, tab);
}
