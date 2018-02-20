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

screen_t *global_bonus(void)
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
	screen->texture = sfTexture_createFromFile(BACK_T, NULL);
	screen->texture2 = sfTexture_createFromFile(MONT_T, NULL);
	screen->texture3 = sfTexture_createFromFile(MONT2_T, NULL);
	screen->texture4 = sfTexture_createFromFile(SUN_T, NULL);
	screen->music_t = init_music_bonus();
	screen->track = 0;
	return (screen);
}

sfMusic **init_music_bonus(void)
{
	sfMusic **music = malloc(sizeof(sfMusic *) * NB_MUSIC);

	music[0] = sfMusic_createFromFile(SONG1_B);
	music[1] = sfMusic_createFromFile(SONG2_B);
	music[2] = sfMusic_createFromFile(SONG2);
	music[3] = sfMusic_createFromFile(SONG3);
	music[4] = sfMusic_createFromFile(SONG4);
	return (music);
}

carac_t *init_caracteres_bonus(void)
{
	carac_t *carac = malloc(sizeof(carac_t));

	carac->emolga = sfSprite_create();
	carac->emolga_attack = sfSprite_create();
	carac->over = sfSprite_create();
	carac->texture_emolga = sfTexture_createFromFile(C1_B, NULL);
	carac->texture_emolga_back = sfTexture_createFromFile(C2_B, NULL);
	carac->texture_emolga_attack = sfTexture_createFromFile(ATTACK_B, NULL);
	carac->loose = 0;
	sfSprite_setTexture(carac->emolga_attack, carac->texture_emolga_attack,
		sfTrue);
	return (carac);
}

move_t *init_move_bonus(move_t *coo)
{
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
	coo->vitesse_enem.x = 0;
	coo->vitesse_enem.y = 540;
	return (coo);
}

sprite_t init_solaroc_bonus(void)
{
	sprite_t solar;
	sfVector2f init_coor = {2000, 2000};

	solar.sprite = sfSprite_create();
	solar.texture = sfTexture_createFromFile(ENEMY_B, NULL);
	solar.acceleration = 30;
	sfSprite_setTexture(solar.sprite, solar.texture, sfTrue);
	sfSprite_setPosition(solar.sprite, init_coor);

	return (solar);
}
