/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

void you_win(sfRenderWindow *Window, sprite_t *sol, carac_t *perso,
	score_t *score)
{
	sfSprite *sprite = sfSprite_create();
	sfTexture *texture = sfTexture_createFromFile(WIN, NULL);
	int tt = 0;

	sfSprite_setTexture(sprite, texture, sfTrue);
	while (tt == 0) {
		sfRenderWindow_clear(Window, sfBlack);
		sfRenderWindow_drawSprite(Window, sprite, NULL);
		if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
			tt = 1;
		if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
			tt = 2;
		sfRenderWindow_drawText(Window, score->text, NULL);
		score->i = 0;
		sfRenderWindow_display(Window);
	} if (tt == 2) {
		sol[1].acceleration = 30;
		perso->loose = 0;
	} if (tt == 1)
		sfRenderWindow_close(Window);
}
