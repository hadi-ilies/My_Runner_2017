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

sfRenderWindow *display_window_one_bonus(screen_t *scre, carac_t *perso)
{
	scre->Window = sfRenderWindow_create(scre->mode, "EMOLGA_SHOOT",
					sfResize | sfClose, NULL);
	if (!scre->Window)
		return (NULL);
	if (!scre->texture)
		return (NULL);
	sfRenderWindow_setFramerateLimit(scre->Window, 30);
	load_texture_bonus(scre, perso);
	return (scre->Window);
}

void display_loop_bonus(screen_t *scre, carac_t *perso)
{
	move_t *coo = malloc(sizeof(move_t));
	sprite_t *sol = solaroc_bonus(NB_SOL);
	score_t *score = load_score();

	coo = init_move_bonus(coo);
	while (sfRenderWindow_isOpen(scre->Window)) {
		input_bonus(scre, perso->loose);
		if (perso->loose == 1)
			game_over(scre->Window, sol, perso, score);
		if (perso->loose == 0) {
			sfRenderWindow_clear(scre->Window, sfBlack);
			display_window_two_bonus(scre, coo, perso);
			enemies_bonus(scre, sol);
			perso->loose = colision_emolga_bonus(perso, sol);
			colision_attack_bonus(perso, sol);
			display_score(scre, score);
			sfRenderWindow_display(scre->Window);
		}
	}
	display_window_three(scre, perso, sol);
}

void display_window_two_bonus(screen_t *scre, move_t *coo, carac_t *perso)
{
	cond_sprite_bonus(coo);
	move_sprite_bonus(scre, coo);
	move_sprite_next_bonus(scre, coo);
	move_emolga_bonus(scre, perso);
	attack_emolga_bonus(scre, perso);
}

int display_window_three_bonus(screen_t *scre, carac_t *perso, sprite_t *sol)
{
	sfRenderWindow_destroy(scre->Window);
	sfTexture_destroy(scre->texture);
	sfTexture_destroy(scre->texture2);
	sfTexture_destroy(scre->texture3);
	sfTexture_destroy(scre->texture4);
	sfTexture_destroy(scre->texture5);
	sfTexture_destroy(perso->texture_emolga_attack);
	sfMusic_destroy(scre->music_t[5]);
	free(scre);
	free(perso);
	free(sol);
	return (EXIT_SUCCESS);
}

void music_bonus(screen_t *scre)
{
	if (scre->track == 0) {
		sfMusic_play(scre->music_t[0]);
	} if (scre->track == 1) {
		sfMusic_destroy(scre->music_t[0]);
		sfMusic_play(scre->music_t[1]);
	} if (scre->track == 2) {
		sfMusic_destroy(scre->music_t[1]);
		sfMusic_play(scre->music_t[2]);
	} if (scre->track == 3) {
		sfMusic_destroy(scre->music_t[2]);
		sfMusic_play(scre->music_t[3]);
	} if (scre->track == 4) {
		sfMusic_destroy(scre->music_t[3]);
		sfMusic_play(scre->music_t[4]);
	} if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue)
		scre->track++;
}
