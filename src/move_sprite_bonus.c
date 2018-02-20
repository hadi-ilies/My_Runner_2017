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

void move_emolga_bonus(screen_t *scre, carac_t *perso)
{
	sfVector2f emolga = {0, 0};

	emolga.y += 5;
	sfSprite_setTexture(perso->emolga, perso->texture_emolga_back, sfTrue);
	if (sfKeyboard_isKeyPressed(sfKeyUp) ==  sfTrue) {
		sfSprite_setTexture(perso->emolga, perso->texture_emolga,
				sfTrue);
		emolga.y -= 25;
	} if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
		emolga.y += 25;
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
		emolga.x += 25;
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
		emolga.x -= 25;
	sfSprite_move(perso->emolga, emolga);
	cond_move_emolga_bonus(perso, emolga, scre);
}

void attack_emolga_bonus(screen_t *scre, carac_t *perso)
{
	sfVector2f emolga_attack = {0, 0};
	sfVector2f emolga_position = {0, 0};

	if (sfKeyboard_isKeyPressed(sfKeySpace) ==  sfTrue) {
		emolga_position = sfSprite_getPosition(perso->emolga);
		sfSprite_setPosition(perso->emolga_attack, emolga_position);
	}
	emolga_attack.x += 50 ;
	sfSprite_move(perso->emolga_attack, emolga_attack);
	sfRenderWindow_drawSprite(scre->Window, perso->emolga_attack, NULL);
}

void load_texture_bonus(screen_t *scre, carac_t *perso)
{
	sfSprite_setTexture(scre->sprite, scre->texture, sfTrue);
	sfSprite_setTexture(scre->sprite2, scre->texture2, sfTrue);
	sfSprite_setTexture(scre->sprite3, scre->texture3, sfTrue);
	sfSprite_setTexture(scre->sprite4, scre->texture4, sfTrue);
	sfSprite_setTexture(perso->emolga, perso->texture_emolga_back, sfTrue);
}

void move_sprite_bonus(screen_t *scre, move_t *coo)
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

int move_sprite_next_bonus(screen_t *scre, move_t *coo)
{
	coo->vitesse.x+= 1920;
	sfSprite_setPosition(scre->sprite3, coo->vitesse);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite3, NULL);
	coo->vitesse.x-= 1920;
	sfSprite_setPosition(scre->sprite3, coo->vitesse);
	return (0);
}
