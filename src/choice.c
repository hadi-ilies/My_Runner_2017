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

screen_t *global(void)
{
	screen_t *screen = malloc(sizeof(screen_t));

	screen->width = WIDTH;
	screen->height = HEIGHT;
	screen->mode.width = screen->width;
	screen->mode.height = screen->height;
	screen->mode.bitsPerPixel = 32;
	screen->sprite = sfSprite_create();
	screen->sprite2 = sfSprite_create();
	screen->sprite3 = sfSprite_create();
	screen->sprite4 = sfSprite_create();
	screen->sprite5 = sfSprite_create();
	screen->texture = sfTexture_createFromFile(BACK, NULL);
	screen->texture2 = sfTexture_createFromFile(MONT, NULL);
	screen->texture3 = sfTexture_createFromFile(MONT2, NULL);
	screen->texture4 = sfTexture_createFromFile(SUN, NULL);
	screen->texture5 = sfTexture_createFromFile(FLOOR, NULL);
	screen->music_t = init_music();
	screen->track = 0;
	return (screen);
}

sfMusic **init_music(void)
{
	sfMusic **music = malloc(sizeof(sfMusic *) * NB_MUSIC);

	music[0] = sfMusic_createFromFile(SONG);
	music[1] = sfMusic_createFromFile(SONG1);
	music[2] = sfMusic_createFromFile(SONG2);
	music[3] = sfMusic_createFromFile(SONG3);
	music[4] = sfMusic_createFromFile(SONG4);
	return (music);
}

carac_t *init_caracteres(void)
{
	carac_t *carac = malloc(sizeof(carac_t));
	sfVector2f emolga = {0, 850};

	carac->emolga = sfSprite_create();
	carac->emolga_attack = sfSprite_create();
	carac->texture_emolga = sfTexture_createFromFile(C1, NULL);
	carac->texture_emolga_back = sfTexture_createFromFile(C2, NULL);
	carac->texture_emolga_attack = sfTexture_createFromFile(ATTACK, NULL);
	carac->loose = 0;
	carac->win = 0;
	sfSprite_setTexture(carac->emolga_attack, carac->texture_emolga_attack,
		sfTrue);
	sfSprite_setPosition(carac->emolga, emolga);

	return (carac);
}

move_t *init_move(move_t *coo)
{
	coo = malloc(sizeof(move_t));
	coo->co2.x = 0;
	coo->co2.y = 0;
	coo->co3.x = 0;
	coo->co3.y = 0;
	coo->co4.x = 0;
	coo->co4.y = 0;
	coo->co5.x = 0;
	coo->co5.y = 0;
	coo->vitesse.x = 0;
	coo->vitesse.y = 0;
	coo->vitesse2.x = 0;
	coo->vitesse2.y = 0;
	coo->vitesse3.x = 0;
	coo->vitesse3.y = 0;
	coo->vitesse4.x = 0;
	coo->vitesse4.y = 0;
	coo->vitesse5.x = 0;
	coo->vitesse5.y = 0;
	return (coo);
}

sprite_t init_solaroc(void)
{
	sprite_t solar;
	sfVector2f init_coor = {2000, 2000};

	solar.sprite = sfSprite_create();
	solar.texture = sfTexture_createFromFile(ENEMY, NULL);
	solar.acceleration = 30;
	sfSprite_setTexture(solar.sprite, solar.texture, sfTrue);
	sfSprite_setPosition(solar.sprite, init_coor);
	return (solar);
}
