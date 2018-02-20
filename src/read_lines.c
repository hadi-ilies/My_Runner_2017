/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"

int coord_o(square *coor)
{
	static int i = 0;

	for (; i < coor->row; i++) {
		if (my_atoi(coor->array[i]) >= 0) {
			coor->x_o = my_atoi(coor->array[i]);
			coor->y_o = my_atoi(coor->array[i + 1]);
			i += 2;
			return (0);
		}
	}
	return (1);
}
