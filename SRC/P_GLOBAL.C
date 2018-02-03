#include "gstudio.h"
#include <stdio.h>

BITMAP *screen_buffer = NULL;
unsigned char game_pal[768];
FONT *font = NULL;
volatile int global_delay = 0;
BITMAP *court = NULL;
BITMAP *logo = NULL;
BITMAP *logo_c = NULL;
volatile int game_difficulty_level = 1; //0 = easy; 1 = normal; 2 = hard;
volatile int game_player1 = 0; //0 = human; 1 = computer;
volatile int game_player2 = 1; //0 = human; 1 = computer;
BITMAP *bar_left = NULL;
BITMAP *bar_right = NULL;
BITMAP *ball[2];
volatile int game_ball_sprite = 0;
