/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"

void ini_map(square *coor, char *str)
{
	coor->loose = 0;
	coor->temp = 0;
	coor->n = 0;
	coor->s = 0;
	coor->vie = 0;
	coor->vitesse = 0;
	coor->b = 0;
	coor->x_o = 0;
	coor->y_o = 0;
	coor->size = 0;
	coor->i = 0;
	coor->j = 0;
	coor->nb_col = 1;
	coor->nb_row = 1;
	coor->row = fs_get_number_from_first_line(str);
	coor->a = (coor->row / 2);
	coor->col = fs_print_first_line(str);
	coor->array = load_2d_arr_from_file(str, coor->row, coor->col);
}
