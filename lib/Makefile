##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC=		my_putstr.c \
		my_atoi.c \
		my_strlen.c \
		my_putchar.c

INC_DIR	=	../include

CFLAGS=		-W -Wall -Wextra -I $(INC_DIR)

OBJ=		$(SRC:.c=.o)

NAME=		libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
