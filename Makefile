##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## first Makefile
##

SRC	=	main.c	\
		setup_sprite.c	\
		circle_draw.c	\
		slider.c	\

NAME	=	my_paint

DFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

COMP	=	gcc -o $(NAME) $(SRC)

all:	$(NAME)

$(NAME):
	$(COMP) $(DFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
