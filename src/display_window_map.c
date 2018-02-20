/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

sfRenderWindow *display_window_one_map(screen_t *scre, carac_t *perso)
{
	scre->Window = sfRenderWindow_create(scre->mode, "Level",
					sfResize | sfClose, NULL);
	if (!scre->Window)
		return (NULL);
	if (!scre->texture)
		return (NULL);
	sfRenderWindow_setFramerateLimit(scre->Window, 30);
	load_texture(scre, perso);
	return (scre->Window);
}

void display_loop_map(screen_t *scre, carac_t *perso, square *coor)
{
	score_t *score = load_score();
	move_t *coo = init_move(coo);
	sprite_t *sol = solaroc_map(coor->a);
	sprite_t *link = init_char();

	while (sfRenderWindow_isOpen(scre->Window)) {
		input(scre, perso->loose);
		perso->loose == 1?game_over(scre->Window, sol, perso, score):0;
		perso->win == 1 ? you_win(scre->Window, sol, perso, score) : 0;
		if (perso->loose == 0 && perso->win == 0) {
			sfRenderWindow_clear(scre->Window, sfBlack);
			display_window_two_map(scre, coo, perso, link);
			perso->win = enemies_map(scre, coor, sol);
			perso->loose = colision_emolga_map(coor, link, sol);
			colision_attack_map(coor, perso, sol);
			display_score(scre, score);
			sfRenderWindow_display(scre->Window);
		}
	}
	display_window_three_map(scre, perso, coor, sol);
}

void display_window_two_map(screen_t *scre, move_t *coo, carac_t *perso,
			sprite_t *link)
{
	cond_sprite(coo);
	move_sprite(scre, coo);
	move_sprite_next(scre, coo);
	move_emolga(scre, link);
	attack_emolga(scre, perso, link);
}

int display_window_three_map(screen_t *scre, carac_t *perso, square *coor,
			sprite_t *sol)
{
	sfRenderWindow_destroy(scre->Window);
	sfTexture_destroy(scre->texture);
	sfTexture_destroy(scre->texture2);
	sfTexture_destroy(scre->texture3);
	sfTexture_destroy(scre->texture4);
	sfTexture_destroy(scre->texture5);
	sfTexture_destroy(perso->texture_emolga_attack);
	free(scre);
	free(coor);
	free(perso);
	free(sol);
	return (EXIT_SUCCESS);
}
