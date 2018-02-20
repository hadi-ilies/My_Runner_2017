/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NB_SOL 10
#define NB_MUSIC 5
#define VAL_ACCELERATION 0.005
#define WIDTH 1920
#define HEIGHT 1080
#define EFFECT "src/music/sound_effect.ogg"
#define WIN "src/DPC/You_Win.png"
#define OVER "src/DPC/game_over.png"
#define BACK "src/DPC/9 Background.png"
#define MONT "src/DPC/2 Layer2.png"
#define MONT2 "src/DPC/1 Layer1.png"
#define SUN "src/DPC/6 Sun.png"
#define FLOOR "src/DPC/floor.png"
#define SONG "src/music/cowboy.ogg"
#define SONG1 "src/music/gorudo_valley.ogg"
#define SONG2 "src/music/gorudo_desert.ogg"
#define SONG3 "src/music/fire_emblem.ogg"
#define SONG4 "src/music/temple_melee.ogg"
#define C1 "src/DPC/link1.png"
#define C2 "src/DPC/link2.png"
#define C3 "src/DPC/link3.png"
#define C4 "src/DPC/link4.png"
#define ATTACK "src/DPC/attack1.png"
#define ENEMY "src/DPC/enemy.png"
#define LIB_TEXT "src/text/font.ttf"
#define BACK_T "src/DPC_BONUS/Sky.png"
#define MONT_T "src/DPC_BONUS/Trees.png"
#define MONT2_T "src/DPC_BONUS/Ground.png"
#define SUN_T  "src/DPC_BONUS/Rocks.png"
#define SONG1_B "src/music_bonus/rayman.ogg"
#define SONG2_B "src/music_bonus/pokemon.ogg"
#define C1_B "src/DPC_BONUS/emolga.png"
#define C2_B "src/DPC_BONUS/emolga2.png"
#define ATTACK_B "src/DPC_BONUS/attack_emolga.png"
#define ENEMY_B "src/DPC_BONUS/images9.png"
#define ANIM_L "src/DPC/run_left.png"
#define ANIM_R "src/DPC/run_right.png"

typedef struct  {
	int loose;
	int temp;
	int s;
	int n;
	int vie;
	int vitesse;
	int a;
	int b;
	int x_o;
	int y_o;
	int size;
	int i;
	int j;
	int col;
	int row;
	int nb_col;
	int nb_row;
	char **array;
	int **int_array;
} square;

typedef struct movement {
	sfVector2f co2;
	sfVector2f co3;
	sfVector2f co4;
	sfVector2f co5;
	sfVector2f vitesse;
	sfVector2f vitesse2;
	sfVector2f vitesse3;
	sfVector2f vitesse4;
	sfVector2f vitesse5;
	sfVector2f vitesse_enem;
} move_t;

typedef struct caracteres {
	sfTexture *texture_emolga;
	sfTexture *texture_emolga_back;
	sfTexture *texture_emolga_attack;
	sfTexture *texture_over;
	sfSprite *emolga;
	sfSprite *emolga_back;
	sfSprite *emolga_attack;
	sfSprite *over;
	int loose;
	int win;
} carac_t;

typedef struct screen {
	int width;
	int height;
	sfVideoMode mode;
	sfRenderWindow *Window;
	sfMusic *music;
	int track;
	sfTexture *texture;
	sfTexture *texture2;
	sfTexture *texture3;
	sfTexture *texture4;
	sfTexture *texture5;
	sfSprite *sprite;
	sfSprite *sprite2;
	sfSprite *sprite3;
	sfSprite *sprite4;
	sfSprite *sprite5;
	sfMusic **music_t;
}screen_t;

typedef struct score{
	sfFont* font;
	sfText* text;
	char *score_msg;
	int i;
} score_t;

typedef struct nb_sprite{
	sfTexture *texture;
	sfSprite *sprite;
	float acceleration;
} sprite_t;

void delete_enemies_map(square *coor, sprite_t *sol, sfVector2f coor_solar);
int my_strlen(char const  *str);
int parsing(void);
int choice (char **argv, screen_t *scre);
screen_t *global(void);
move_t *init_move(move_t *coo);
void cond_sprite(move_t *coo);
void sprite(screen_t *scre, move_t *coo, carac_t *perso);
void move_sprite(screen_t *scre, move_t *coo);
int move_sprite_next(screen_t *scre, move_t *coo);
carac_t *init_caracteres(void);
void sprite_caract(screen_t *scre, move_t *coo, carac_t *perso);
sprite_t init_solaroc(void);
sprite_t *solaroc(int nb_solaroc);
int colision_cor(sfFloatRect carre, sfVector2f point);
int colision(sfSprite *sprite1, sfSprite *sprite2);
sfMusic **init_music(void);
void help(void);
void ini_map(square *coor, char *str);
int count_char_line(char const *filepath);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
int fs_print_first_line(char const *filepath);
int fs_get_number_from_first_line(char const *filepath);
int fs_open_file (char const *filepath);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
int my_atoi(char *str);
void count_enemies(square *coor);
sprite_t *solaroc_map(int nb_solaroc);
int enemies_map(screen_t *scre, square *coor, sprite_t *sol);
void enemies(screen_t *scre, sprite_t *sol);
void ini_map(square *coor, char *str);
sfRenderWindow *display_window_one_map(screen_t *scre, carac_t *perso);
void display_loop_map(screen_t *scre, carac_t *perso, square *coor);
void display_window_two_map(screen_t *scre, move_t *coo, carac_t *perso,
			sprite_t *link);
int display_window_three_map(screen_t *scre, carac_t *perso
		, square *coor, sprite_t *sol);
void music_map (screen_t *scre);
int colision_emolga_map(square *coor, sprite_t *link, sprite_t *sol);
void colision_attack_map(square *coor, carac_t *perso, sprite_t *sol);
int alea(int min, int max);
void load_texture(screen_t *scre, carac_t *perso);
void move_sprite(screen_t *scre, move_t *coo);
int move_sprite_next (screen_t *scre, move_t *coo);
score_t *init_score(void);
sprite_t *init_char(void);
sprite_t init_solaroc(void);
void input(screen_t *scre, int loose);
void my_putstr(const char *str);
void music_game_over(screen_t *scre);
void nb_enemies(square *coor);
void attack_emolga(screen_t *scre, carac_t *perso, sprite_t *link);
void move_emolga(screen_t *scre, sprite_t *link);
void display_loop(screen_t *scre, carac_t *perso);
void display_window_two(screen_t *scre, move_t *coo,
			carac_t *perso, sprite_t *link);
int display_window_three(screen_t *scre, carac_t *perso, sprite_t *sol);
sfRenderWindow *display_window_one(screen_t *scre, carac_t *perso);
sprite_t *solaroc(int nb_solaroc);
void colision_attack(carac_t *perso, sprite_t *sol);
int colision_emolga(sprite_t *link, sprite_t *sol);
int coord_o(square *coor);
void parsing_next(char **argv);
void parsing_next_two(char **argv, screen_t *scre, carac_t *perso,
		square *map);
screen_t *global_bonus(void);
sfMusic **init_music_bonus(void);
carac_t *init_caracteres_bonus(void);
move_t *init_move_bonus(move_t *coo);
sprite_t init_solaroc_bonus(void);
int move_sprite_next_bonus(screen_t *scre, move_t *coo);
void move_sprite_bonus(screen_t *scre, move_t *coo);
void load_texture_bonus(screen_t *scre, carac_t *perso);
void attack_emolga_bonus(screen_t *scre, carac_t *perso);
void move_emolga_bonus(screen_t *scre, carac_t *perso);
void cond_sprite_bonus(move_t *coo);
sfRenderWindow *display_window_one_bonus(screen_t *scre, carac_t *perso);
void display_loop_bonus(screen_t *scre, carac_t *perso);
void display_window_two_bonus(screen_t *scre, move_t *coo, carac_t *perso);
int display_window_three_bonus(screen_t *scre, carac_t *perso, sprite_t *sol);
void enemies_bonus(screen_t *scre, sprite_t *sol);
void colision_attack_bonus(carac_t *perso, sprite_t *sol);
int colision_emolga_bonus(carac_t *perso, sprite_t *sol);
sprite_t *solaroc_bonus(int nb_solaroc);
void input_bonus(screen_t *scre, int loose);
void music_bonus(screen_t *scre);
score_t *load_score(void);
void display_score(screen_t *scre, score_t *score);
void cond_move_emolga(sprite_t *link, sfVector2f *emolga , screen_t *scre);
void cond_move_emolga_bonus(carac_t *perso, sfVector2f emolga, screen_t *scre);
char *concat(char *s1, char *s2);
char *inttostr(int nb);
void game_over(sfRenderWindow *Window, sprite_t *sol,
	carac_t *perso, score_t *score);
void delete_enemies(sprite_t *sol, sfVector2f coor_solar);
void move_emolga_next2(sfIntRect *rectangle, sprite_t *link,
		sfVector2f *emolga);
void move_emolga_next(int *i, sfIntRect *rectangle, int *spri,
		float *speed_char);
void cond_gravity(sfVector2f *emolga);
int my_atoi(char *str);
void you_win(sfRenderWindow *Window, sprite_t *sol, carac_t *perso,
	score_t *score);
void cond_move_sprite2(screen_t *scre, move_t *coo);
