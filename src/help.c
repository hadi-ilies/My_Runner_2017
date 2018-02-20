/*
** EPITECH PROJECT, 2017
** help
** File description:
** help
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include <stdio.h>

void help(void)
{
	my_putstr("Finite runner created width CSFML.\n");
	my_putstr("USAGE\n");
	my_putstr("	./my_runner map.txt\n");
	my_putstr("	./my_runner -i\n");
	my_putstr("	./my_runner -e\n");
	my_putstr("OPTIONS\n");
	my_putstr("-e		lauch the game in another mode.\n");
	my_putstr("-i		lauch the game in infinity mode.\n");
	my_putstr("-h		print the usage and quit.\n");
	my_putstr("USER INTERACTIONS\n");
	my_putstr("UP_KEY		TO MOVE UP.\n");
	my_putstr("DOWN_KEY		TO MOVE DOWN.\n");
	my_putstr("RIGHT_KEY		TO MOVE RIGHT.\n");
	my_putstr("LEFT_KEY		TO MOVE LEFT.\n");
	my_putstr("SPACE_KEY		TO ATTACK.\n");
	my_putstr("M_KEY		TO PLAY MUSIC.\n");
	my_putstr("R_KEY		TO RESTART.\n");
	my_putstr("Q_KEY		EXIT.\n");
}
