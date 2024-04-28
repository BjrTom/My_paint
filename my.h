/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** proto case
*/

#ifndef STN
    #define STN

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct slider {
    sfRectangleShape *line;
    sfRectangleShape *line2;
    sfRectangleShape *button;
    int rayon;
} sld_t;

typedef struct drawing_board {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
} image_t;

typedef struct value {
    sfRenderWindow *window;
    sfEvent event;
    int nb_color;
    sfColor selec_color;
    sfColor old_color;
    sfVector2i m;
    sfVector2i mouse_prev;
    sfVector2f selecpos;
    sfColor *c_tab;
    image_t *im;
    bool state;
}value;

typedef struct object {
    sfSprite *cat;
    sfSprite *brush;
    sfSprite *eraser;
    sfSprite *save;
    sfRectangleShape *menu;
    sfRectangleShape *selec;
    sfRectangleShape *task;
    sfRectangleShape *line;
    sfRectangleShape *line2;
    sfRectangleShape *linev;
    sfRectangleShape *is_select;
    bool state;
    sld_t *sld;
}object;

typedef struct default_button {
    sfRectangleShape *rect;
    int active;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
}button;

void startup(value *, object *);
int my_printf(const char *str, ...);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *, char *);
char my_putchar(char c);
int my_strlen(char *str);
int my_getnbr(const char *str);
void my_putstr(char const *str);
int my_strlen_n(char const *str);
char *my_strdup(char *);
char **my_str_to_word_array(char *str);
void free_tab(int nb, char **tab);
void circle_draw(value *info, image_t *im, int const rayon);
void circle_ring_draw(image_t *im, value *info, int x, int y);
image_t *create_new_image(int, char **);
void setup(object *obj);
sfRectangleShape *my_line(int x, int y, int a, int b);
int slider_change(object *obj, value *v);
void all_destroy(value *v, object *obj, button **tab);
int save(value *v);

#endif
