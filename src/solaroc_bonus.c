/*
** EPITECH PROJECT, 2017
** solaroc
** File description:
** solaroc
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

sprite_t *solaroc_bonus(int nb_solaroc)
{
	sprite_t *solaroc = malloc(sizeof(sprite_t) * nb_solaroc);

	for (int i = 0; i < nb_solaroc; i++)
		solaroc[i] = init_solaroc_bonus();

	return (solaroc);
}

int colision_emolga_bonus(carac_t *perso, sprite_t *sol)
{
	sfVector2f coor_solar = {2000, 2000};

	for (int i = 0; i < NB_SOL; i++) {
		if (colision(perso->emolga, sol[i].sprite) == 1) {
			delete_enemies(sol, coor_solar);
			return (1);
		} if (colision(sol[i].sprite, perso->emolga) == 1) {
			delete_enemies(sol, coor_solar);
			return (1);
		}
	}
	return (0);
}

void colision_attack_bonus(carac_t *perso, sprite_t *sol)
{
	sfVector2f solar_poub = {2000, 2000};

	for (int i = 0; i < NB_SOL; i++) {
		if (colision(perso->emolga_attack, sol[i].sprite) == 1) {
			sfMusic_play(sfMusic_createFromFile(EFFECT));
			sfSprite_setPosition(sol[i].sprite, solar_poub);
		} if (colision(sol[i].sprite, perso->emolga_attack) == 1) {
			sfMusic_play(sfMusic_createFromFile(EFFECT));
			sfSprite_setPosition(sol[i].sprite, solar_poub);
		}
	}
}

void enemies_bonus(screen_t *scre, sprite_t *sol)
{
	sfVector2f coor_solar = {0, 0};

	for (int i = 0; i < NB_SOL; i++) {
		coor_solar = sfSprite_getPosition(sol[i].sprite);
		if (coor_solar.x <= -192) {
			coor_solar.x = (rand() % ( 10000 - 1920 + 1)) + 1920;
			coor_solar.y = (rand() % ( 1080 - 0 + 1)) + 0;
		}
		coor_solar.x -= sol[1].acceleration;
		sol[1].acceleration += VAL_ACCELERATION;
		sfSprite_setPosition(sol[i].sprite, coor_solar);
		sfRenderWindow_drawSprite(scre->Window, sol[i].sprite, NULL);
	}
}
