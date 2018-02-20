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

sprite_t *solaroc_map(int nb_solaroc)
{
	sprite_t *solaroc = malloc(sizeof(sprite_t) * nb_solaroc);

	for (int i = 0; i < nb_solaroc; i++)
		solaroc[i] = init_solaroc();

	return (solaroc);
}

int enemies_map(screen_t *scre, square *coor, sprite_t *sol)
{
	sfVector2f coor_solar = {0, 0};
	static int happy_end = 0;
	int final = -1000;
	static int qsdf = 0;

	for (int i = 0; i < coor->a; i++) {
		coor_solar = sfSprite_getPosition(sol[i].sprite);
		final < coor_solar.x ? final = coor_solar.x : 0;
		if (coor_solar.x < -100 && qsdf == 0) {
			happy_end = coord_o(coor);
			coor_solar.x = coor->x_o;
			coor_solar.y = coor->y_o;
			happy_end == 1 ? qsdf++ : 0;
		}
		coor_solar.x -= sol[1].acceleration;
		sol[1].acceleration += VAL_ACCELERATION;
		sfSprite_setPosition(sol[i].sprite, coor_solar);
		sfRenderWindow_drawSprite(scre->Window, sol[i].sprite, NULL);
	}
	return (happy_end == 1 && final <= -100 ? 1 : 0);
}

int colision_emolga_map(square *coor, sprite_t *link, sprite_t *sol)
{
	sfVector2f coor_solar = {2000, 2000};

	for (int i = 0; i < coor->a; i++) {
		if (colision(link[0].sprite, sol[i].sprite) == 1) {
			delete_enemies_map(coor, sol, coor_solar);
			return (1);
		} if (colision(sol[i].sprite, link[0].sprite) == 1) {
			delete_enemies_map(coor, sol, coor_solar);
			return (1);
		}
	}
	return (0);
}

void colision_attack_map(square *coor, carac_t *perso, sprite_t *sol)
{
	sfVector2f solar_poub = {2000, 2000};

	for (int i = 0; i < coor->a; i++) {
		if (colision(perso->emolga_attack, sol[i].sprite) == 1) {
			sfMusic_play(sfMusic_createFromFile(EFFECT));
			sfSprite_setPosition(sol[i].sprite, solar_poub);
		} if (colision(sol[i].sprite, perso->emolga_attack) == 1) {
			sfMusic_play(sfMusic_createFromFile(EFFECT));
			sfSprite_setPosition(sol[i].sprite, solar_poub);
		}
	}
}
