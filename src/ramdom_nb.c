/*
** EPITECH PROJECT, 2018
** random
** File description:
** ramdom
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

int alea(int min, int max)
{
	int result = 0;

	result = (rand() % ( max - min  + 1)) + min;
	return (result);
}
