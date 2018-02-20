/*
** EPITECH PROJECT, 2018
** delete
** File description:
** delete
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

void delete_enemies_map(square *coor, sprite_t *sol, sfVector2f coor_solar)
{
	for (int j = 0; j < coor->a; j++)
		sfSprite_setPosition(sol[j].sprite, coor_solar);
}
