##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC=		$(SRC_DIR)runner.c	\
		$(SRC_DIR)map.c \
		$(SRC_DIR)read_lines.c	\
		$(SRC_DIR)display_window_map.c \
		$(SRC_DIR)display_window_bonus.c \
		$(SRC_DIR)solaroc_bonus.c \
		$(SRC_DIR)display_window.c \
		$(SRC_DIR)enemies_and_colision.c \
		$(SRC_DIR)move_sprite_bonus.c \
		$(SRC_DIR)cond_move_emolga.c \
		$(SRC_DIR)move_sprite.c \
		$(SRC_DIR)help.c \
		$(SRC_DIR)solaroc.c \
		$(SRC_DIR)score.c \
		$(SRC_DIR)init_map.c \
		$(SRC_DIR)input.c \
		$(SRC_DIR)read_files.c \
		$(SRC_DIR)mem_array.c \
		$(SRC_DIR)choice.c \
		$(SRC_DIR)choice_bonus.c\
		$(SRC_DIR)ramdom_nb.c \
		$(SRC_DIR)cond_sprite_bonus.c\
		$(SRC_DIR)cond_move_sprite.c \
		$(SRC_DIR)delete_enemies_map.c \
		$(SRC_DIR)choice_two.c \
		$(SRC_DIR)you_win.c \
		$(SRC_DIR)cond_move_sprite2.c \
		$(SRC_DIR)my_music.c

SRC_DIR	=	src/

INC_DIR	=	include/

LIB_DIR	=	lib/

OBJ=            $(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I $(INC_DIR) -g

LDFLAGS	=	-L $(LIB_DIR) -lmy -lm -lc_graph_prog

NAME=		my_runner

all:            $(NAME)

$(NAME):        $(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		make clean -C $(LIB_DIR)
		rm -f $(OBJ)

fclean:		clean
		make fclean -C $(LIB_DIR)
		rm -f $(NAME)

re:		fclean all
