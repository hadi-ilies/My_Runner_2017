/*
** EPITECH PROJECT, 2018
** music
** File description:
** music
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

void music_map (screen_t *scre)
{
	if (scre->track == 0) {
		sfMusic_play(scre->music_t[0]);
	} if (scre->track == 1) {
		sfMusic_destroy(scre->music_t[0]);
		sfMusic_play(scre->music_t[1]);
	} if (scre->track == 2) {
		sfMusic_destroy(scre->music_t[1]);
		sfMusic_play(scre->music_t[2]);
	} if (scre->track == 3) {
		sfMusic_destroy(scre->music_t[2]);
		sfMusic_play(scre->music_t[3]);
	} if (scre->track == 4) {
		sfMusic_destroy(scre->music_t[3]);
		sfMusic_play(scre->music_t[4]);
	} if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue)
		scre->track++;
}
