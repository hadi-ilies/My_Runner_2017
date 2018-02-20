/*
** EPITECH PROJECT, 2017
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

score_t *load_score()
{
	score_t *score = init_score();

	sfText_setFont(score->text, score->font);
	return (score);
}

void display_score(screen_t *scre, score_t *score)
{
	char *nb = malloc(sizeof(char) * 10);
	char *str = malloc(sizeof(char) * 30);

	nb = inttostr(score->i++);
	score->score_msg = "Score : ";
	str = concat(score->score_msg, nb);
	sfText_setString(score->text, str);
	sfRenderWindow_drawText(scre->Window, score->text, NULL);
}

char *inttostr(int nb)
{
	char *str = malloc(sizeof(char) * 20);
	int size = 1;

	if (nb == 0)
		return ("0");
	for (int nb2 = nb; nb2 >= 10; nb2 /= 10)
		size++;
	for (int i = 0; i <= size; i++)
		str[i] = '\0';
	for (int j = 1; nb > 0 ; j++) {
		str[size - j] =  nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

char *concat(char *s1, char *s2)
{
	int c = 0;
	char *str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));

	for (int i = 0; s1[i] != '\0'; i++) {
		str[c] = s1[i];
		c++;
	}
	for (int j = 0; s2[j] != '\0'; j++) {
		str[c] = s2[j];
		c++;
	}
	str[c] = '\0';
	return (str);
}
