/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

void parsing_next(char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0')
		help();
}

void parsing_next_two(char **argv, screen_t *scre, carac_t *perso, square *map)
{
	if (argv[1][0] == '-' && argv[1][1] == 'i' && argv[1][2] == '\0') {
		scre = global();
		perso = init_caracteres();
		scre->Window = display_window_one(scre, perso);
		display_loop(scre, perso);
	} if (argv[1][0] != '-') {
		scre = global();
		ini_map(map, argv[1]);
		perso = init_caracteres();
		scre->Window = display_window_one_map(scre, perso);
		display_loop_map(scre, perso, map);
	}
}

int main(int argc, char **argv)
{
	screen_t *scre;
	carac_t *perso;
	square *map = malloc(sizeof(square));

	if (argc != 2)
		return (84);
	parsing_next(argv);
	if (argv[1][0] == '-' && argv[1][1] == 'e' && argv[1][2] == '\0') {
		scre = global_bonus();
		perso = init_caracteres_bonus();
		scre->Window = display_window_one_bonus(scre, perso);
		display_loop_bonus(scre, perso);
	}
	parsing_next_two(argv, scre, perso, map);
	return (0);
}
