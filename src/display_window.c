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

sfRenderWindow *display_window_one(screen_t *scre, carac_t *perso)
{
	scre->Window = sfRenderWindow_create(scre->mode, "LINK_RUNNER",
					sfResize | sfClose, NULL);
	if (!scre->Window)
		return (NULL);
	if (!scre->texture)
		return (NULL);
	sfRenderWindow_setFramerateLimit(scre->Window, 30);
	load_texture(scre, perso);
	return (scre->Window);
}

void game_over(sfRenderWindow *Window, sprite_t *sol, carac_t *perso,
	score_t *score)
{
	sfSprite *sprite = sfSprite_create();
	sfTexture *texture = sfTexture_createFromFile(OVER, NULL);
	int tt = 0;

	sfSprite_setTexture(sprite, texture, sfTrue);
	while (tt == 0) {
		sfRenderWindow_clear(Window, sfBlack);
		sfRenderWindow_drawSprite(Window, sprite, NULL);
		if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
			tt = 1;
		if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
			tt = 2;
		sfRenderWindow_drawText(Window, score->text, NULL);
		score->i = 0;
		sfRenderWindow_display(Window);
	} if (tt == 2) {
		sol[1].acceleration = 30;
		perso->loose = 0;
	} if (tt == 1)
		  sfRenderWindow_close(Window);
}

void display_loop(screen_t *scre, carac_t *perso)
{
	move_t *coo = init_move(coo);
	sprite_t *sol = solaroc_map(NB_SOL);
	sprite_t *link = init_char();
	score_t *score = load_score();

	while (sfRenderWindow_isOpen(scre->Window)) {
		input(scre, perso->loose);
		if (perso->loose == 1)
			game_over(scre->Window, sol, perso, score);
		if (perso->loose == 0) {
			sfRenderWindow_clear(scre->Window, sfBlack);
			display_window_two(scre, coo, perso, link);
			enemies(scre, sol);
			perso->loose = colision_emolga(link, sol);
			colision_attack(perso, sol);
			display_score(scre, score);
			sfRenderWindow_display(scre->Window);
		}
	}
	display_window_three(scre, perso, sol);
}

void display_window_two(screen_t *scre, move_t *coo, carac_t *perso,
			sprite_t *link)
{
	cond_sprite(coo);
	move_sprite(scre, coo);
	move_sprite_next(scre, coo);
	move_emolga(scre, link);
	attack_emolga(scre, perso, link);
}

int display_window_three(screen_t *scre, carac_t *perso, sprite_t *sol)
{
	sfRenderWindow_destroy(scre->Window);
	sfTexture_destroy(perso->texture_emolga_attack);
	free(scre);
	free(perso);
	free(sol);
	return (EXIT_SUCCESS);
}
