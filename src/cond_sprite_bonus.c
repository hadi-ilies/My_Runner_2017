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

void cond_sprite_bonus(move_t *coo)
{
	if (coo->vitesse.x <= -1920)
		coo->vitesse.x = 0;
	if (coo->vitesse2.x <= -1920)
		coo->vitesse2.x = 0;
	if (coo->vitesse3.x <= -1920)
		coo->vitesse3.x = 0;
	if (coo->vitesse4.y >= 1080)
		coo->vitesse4.y = 0;
	if (coo->vitesse_enem.x <= -1920)
		coo->vitesse_enem.x = 0;

	coo->vitesse.x -= 3;
	coo->vitesse2.x -= 1.5;
	coo->vitesse3.x -= 2;
	coo->vitesse4.y += 0.001;
	coo->vitesse_enem.x -= 6;
}
