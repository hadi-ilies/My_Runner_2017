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

void move_emolga(screen_t *scre, sprite_t *link)
{
	static sfVector2f emolga = {0, 0};
	static sfIntRect rectangle = {0, 0, 84, 84};
	static int i = 0;
	static int spri = 0;
	float speed_char = 10;

	sfSprite_setTexture(link[0].sprite, link[0].texture, sfTrue);
	cond_gravity(&emolga);
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		sfSprite_setTexture(link[0].sprite, link[0].texture, sfTrue);
		emolga.x += 25;
		speed_char = 1;
	} if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		sfSprite_setTexture(link[0].sprite, link[1].texture, sfTrue);
		emolga.x -= 25;
		speed_char = 20;
	}
	move_emolga_next2(&rectangle, link, &emolga);
	move_emolga_next(&i, &rectangle, &spri, &speed_char);
	cond_move_emolga(link, &emolga, scre);
}

void move_emolga_next(int *i, sfIntRect *rectangle, int *spri,
		float *speed_char)
{
	(*spri)++;
	if (*spri > *speed_char) {
		*spri = 0;
		(*i)++;
		rectangle->left += rectangle->width;
	}
	(*i == 3) ? rectangle->left = 0 : 0;
	(*i == 3) ? *i = 0 : 0;
}
void attack_emolga(screen_t *scre, carac_t *perso, sprite_t *link)
{
	sfVector2f emolga_attack = {0, 0};
	sfVector2f emolga_position = {0, 0};

	if (sfKeyboard_isKeyPressed(sfKeySpace) ==  sfTrue) {
		emolga_position = sfSprite_getPosition(link[0].sprite);
		sfSprite_setPosition(perso->emolga_attack, emolga_position);
	}
	emolga_attack.x += 50 ;
	sfSprite_move(perso->emolga_attack, emolga_attack);
	sfRenderWindow_drawSprite(scre->Window, perso->emolga_attack, NULL);
}

void load_texture(screen_t *scre, carac_t *perso)
{
	sfSprite_setTexture(scre->sprite, scre->texture, sfTrue);
	sfSprite_setTexture(scre->sprite2, scre->texture2, sfTrue);
	sfSprite_setTexture(scre->sprite3, scre->texture3, sfTrue);
	sfSprite_setTexture(scre->sprite4, scre->texture4, sfTrue);
	sfSprite_setTexture(scre->sprite5, scre->texture5, sfTrue);
	sfSprite_setTexture(perso->emolga, perso->texture_emolga_back, sfTrue);
}

void move_sprite(screen_t *scre, move_t *coo)
{
	sfRenderWindow_drawSprite(scre->Window, scre->sprite, NULL);
	coo->vitesse3.x+= 1920;
	sfSprite_setPosition(scre->sprite, coo->vitesse3);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite, NULL);
	coo->vitesse3.x -= 1920;
	sfSprite_setPosition(scre->sprite, coo->vitesse3);
	sfSprite_setPosition(scre->sprite3, coo->vitesse);
	sfSprite_setPosition(scre->sprite4, coo->vitesse4);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite4, NULL);
	coo->vitesse4.y -= 1080;
	sfSprite_setPosition(scre->sprite4, coo->vitesse4);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite4, NULL);
	coo->vitesse4.y += 1080;
	sfSprite_setPosition(scre->sprite4, coo->vitesse4);
	cond_move_sprite2(scre, coo);
}
