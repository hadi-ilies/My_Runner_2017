/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void input(screen_t *scre, int loose)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(scre->Window, &event)) {
		if (event.type == sfEvtKeyPressed
		&& sfKeyboard_isKeyPressed(sfKeyM) == sfTrue
		&& loose == 0)
			music_map(scre);
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(scre->Window);
	}
}

void input_bonus(screen_t *scre, int loose)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(scre->Window, &event)) {
		if (event.type == sfEvtKeyPressed
		&& sfKeyboard_isKeyPressed(sfKeyM) == sfTrue
		&& loose == 0)
			music_bonus(scre);
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(scre->Window);
	}
}
