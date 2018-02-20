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

int colision_cor(sfFloatRect carre, sfVector2f point)
{
	if (point.x >= carre.left &&  point.y >= carre.top
	&& point.y <= carre.top + carre.height
	&& point.x <= carre.left + carre.width)
		return (1);
	else
		return (0);
}

void cond_colision2(sfFloatRect *sprite_two, sfVector2f *point_b,
		sfVector2f *point_c, sfVector2f *point_d)
{
	point_b->x = sprite_two->left + sprite_two->width;
	point_b->y = sprite_two->top + sprite_two->height;
	point_c->x = sprite_two->left;
	point_c->y = sprite_two->top + sprite_two->height;
	point_d->x = sprite_two->left + sprite_two->width;
	point_d->y = sprite_two->top;
}

void cond_colision(sfFloatRect *sprite_two, sfVector2f *point_a)
{
	point_a->x = sprite_two->left;
	point_a->y = sprite_two->top;
}
int colision(sfSprite *sprite1, sfSprite *sprite2)
{
	sfFloatRect sprite_one = {0, 0, 0, 0};
	sfFloatRect sprite_two = {0, 0, 0, 0};
	sfVector2f point_a = {0, 0};
	sfVector2f point_b = {0, 0};
	sfVector2f point_c = {0, 0};
	sfVector2f point_d = {0, 0};

	sprite_one = sfSprite_getGlobalBounds(sprite1);
	sprite_two = sfSprite_getGlobalBounds(sprite2);
	cond_colision(&sprite_two, &point_a);
	cond_colision2(&sprite_two, &point_b, &point_c, &point_d);
	if (colision_cor(sprite_one, point_a) == 1)
		return (1);
	if (colision_cor(sprite_one, point_b) == 1)
		return (1);
	if (colision_cor(sprite_one, point_c) == 1)
		return (1);
	if (colision_cor(sprite_one, point_d) == 1)
		return (1);
	return (0);
}
