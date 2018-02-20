/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int fs_open_file (char const *filepath)
{
	int file = 0;

	file = open(filepath, O_RDONLY);
	if (file == -1)
		exit(84);
	else
		return (file);
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
	char **array;

	array = malloc(sizeof(char *) * nb_rows);
	for (int i = 0; i < nb_rows; i++)
		array[i] = malloc(sizeof(char) * nb_cols);

	return (array);
}
