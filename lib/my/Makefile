##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC	= 	my_putchar.c			\
		my_putstr.c			\
		my_strlen.c			\
		conditional.c			\
		move_check.c			\
		make_map.c			\
		move_player.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
	$(NAME)
