/*
** EPITECH PROJECT, 2018
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

void cond_sprite(move_t *coo)
{
	if (coo->vitesse.x <= -1920)
		coo->vitesse.x = 0;
	if (coo->vitesse2.x <= -1920)
		coo->vitesse2.x = 0;
	if (coo->vitesse3.x <= -1920)
		coo->vitesse3.x = 0;
	if (coo->vitesse4.y >= 1080)
		coo->vitesse4.y = 0;
	if (coo->vitesse5.x <= -1920)
		coo->vitesse5.x = 0;

	coo->vitesse.x -= 3;
	coo->vitesse2.x -= 1.5;
	coo->vitesse3.x -= 2;
	coo->vitesse4.y += 0.001;
	coo->vitesse5.x -= 10;
}

void cond_gravity(sfVector2f *emolga)
{
	sfKeyboard_isKeyPressed(sfKeyUp) ==  sfTrue ? emolga->y -= 0.5 : 0;
	sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue ? emolga->y += 3 : 0;
}

void move_emolga_next2(sfIntRect *rectangle, sprite_t *link, sfVector2f *emolga)
{
	emolga->y += 2;
	emolga->x /= 2;
	sfSprite_setTextureRect(link[0].sprite, *rectangle);
	sfSprite_move(link[0].sprite, *emolga);
}

int move_sprite_next (screen_t *scre, move_t *coo)
{
	coo->vitesse.x += 1920;
	sfSprite_setPosition(scre->sprite3, coo->vitesse);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite3, NULL);
	coo->vitesse.x -= 1920;
	sfSprite_setPosition(scre->sprite3, coo->vitesse);
	sfSprite_setPosition(scre->sprite5, coo->vitesse5);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite5, NULL);
	coo->vitesse5.x += 1920;
	sfSprite_setPosition(scre->sprite5, coo->vitesse5);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite5, NULL);
	coo->vitesse5.x -= 1920;
	sfSprite_setPosition(scre->sprite5, coo->vitesse5);
	return (0);
}
