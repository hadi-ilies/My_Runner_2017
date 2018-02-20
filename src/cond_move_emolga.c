/*
** EPITECH PROJECT, 2017
** cond
** File description:
** cond
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

void cond_move_emolga_bonus(carac_t *perso, sfVector2f emolga, screen_t *scre)
{
	if (sfSprite_getPosition(perso->emolga).y >= HEIGHT - 50) {
		emolga.y = HEIGHT - 50;
		emolga.x = sfSprite_getPosition(perso->emolga).x;
		sfSprite_setPosition(perso->emolga, emolga);
	}if (sfSprite_getPosition(perso->emolga).x >= WIDTH - 50) {
		emolga.x = WIDTH - 50;
		emolga.y = sfSprite_getPosition(perso->emolga).y;
		sfSprite_setPosition(perso->emolga, emolga);
	}if (sfSprite_getPosition(perso->emolga).x <= 0) {
		emolga.x = 0;
		emolga.y = sfSprite_getPosition(perso->emolga).y;
		sfSprite_setPosition(perso->emolga, emolga);
	}if (sfSprite_getPosition(perso->emolga).y <= 0) {
		emolga.y = 0;
		emolga.x = sfSprite_getPosition(perso->emolga).x;
		sfSprite_setPosition(perso->emolga, emolga);
	}
	sfRenderWindow_drawSprite(scre->Window, perso->emolga, NULL);
}

void cond_move_emolga(sprite_t *link, sfVector2f *emolga, screen_t *scre)
{
	sfVector2f emolga_t = {0, 0};

	if (sfSprite_getPosition(link[0].sprite).y >= 850) {
		emolga_t.y = 850;
		emolga->y = 0;
		if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
			emolga->y -= 35;
		emolga_t.x = sfSprite_getPosition(link[0].sprite).x;
		sfSprite_setPosition(link[0].sprite, emolga_t);
	}if (sfSprite_getPosition(link[0].sprite).x >= WIDTH - 50) {
		emolga_t.x = WIDTH - 50;
		emolga_t.y = sfSprite_getPosition(link[0].sprite).y;
		sfSprite_setPosition(link[0].sprite, emolga_t);
	}if (sfSprite_getPosition(link[0].sprite).x <= 0) {
		emolga_t.x = 0;
		emolga_t.y = sfSprite_getPosition(link[0].sprite).y;
		sfSprite_setPosition(link[0].sprite, emolga_t);
	}
	sfRenderWindow_drawSprite(scre->Window, link[0].sprite, NULL);
}
