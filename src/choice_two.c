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

sprite_t *init_char()
{
	sprite_t *main_c = malloc(sizeof(sprite_t) * 4);
	sfVector2f link = {0, 850};

	main_c[0].sprite = sfSprite_create();
	main_c[0].texture = sfTexture_createFromFile(ANIM_R, NULL);
	main_c[1].texture = sfTexture_createFromFile(ANIM_L, NULL);
	sfSprite_setPosition(main_c[0].sprite, link);
	return (main_c);
}

score_t *init_score()
{
	score_t *score = malloc(sizeof(score_t));

	score->font = sfFont_createFromFile(LIB_TEXT);
	score->text =  sfText_create();
	score->score_msg = malloc(sizeof(char) * 200);
	score->i = 0;
	return (score);
}
