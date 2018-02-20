/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** BSQ
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int count_char_line(char const *filepath)
{
	int size = 0;
	int x = 5000000;
	int fd = fs_open_file(filepath);
	char *buffer = malloc(sizeof(char *) * x);

	read(fd, buffer, x);
	for (; buffer[size] != '\n'; size++);
	return (size + 1);
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
	int j = 0;
	int i = 0;
	int s =  ((nb_rows + 1) * (nb_cols + 1) + 2);
	char **array =  mem_alloc_2d_array(nb_rows, nb_cols);
	int fd = fs_open_file(filepath);
	char *buffer = malloc(sizeof(char *) * s);
	read(fd, buffer, count_char_line(filepath));
	int n = read(fd, buffer, s);

	for (int k = 0; k != n - 1; k++) {
		if (buffer[k] == '\n') {
			array[i][j] = '\0';
			j = 0;
			i++;
			k++;
		}
		array[i][j] = buffer[k];
		j++;
	}
	return (array);
}

int fs_print_first_line(char const *filepath)
{
	int col = 0;
	int skip;
	int x = 5000000;
	int fd = fs_open_file(filepath);
	char *buffer = malloc(sizeof(char *) * x);

	read(fd, buffer, x);
	for (skip = 0; buffer[skip] != '\n' ; skip++);
	skip++;
	for (; buffer[skip] != '\n'; skip++)
		col++;
	return (col);
}

int fs_get_number_from_first_line(char const *filepath)
{
	int n = 0;
	int x = 5000000;
	int file = 0;
	char *buffer = malloc(sizeof(char *) * x + 1);

	file = open(filepath, O_RDONLY);
	read(file, buffer, x);
	if (file == -1)
		return (-1);
	else if (file > 0) {
		for (int size = 0; buffer[size] != '\n'; size++) {
			if (my_atoi(buffer) >= 0)
				n = my_atoi(buffer);
			if (my_atoi(buffer) < 0)
				return (-1);
		}
	}
	return (n);
}
