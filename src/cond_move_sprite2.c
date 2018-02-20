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

void cond_move_sprite2(screen_t *scre, move_t *coo)
{
	sfSprite_setPosition(scre->sprite2, coo->vitesse2);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite2, NULL);
	coo->vitesse2.x+= 1920;
	sfSprite_setPosition(scre->sprite2, coo->vitesse2);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite2, NULL);
	coo->vitesse2.x-= 1920;
	sfSprite_setPosition(scre->sprite3, coo->vitesse);
	sfRenderWindow_drawSprite(scre->Window, scre->sprite3, NULL);
}
