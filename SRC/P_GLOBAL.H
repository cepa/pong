#ifndef __P_GLOBAL_H__
  #define __P_GLOBAL_H__

  #include "gstudio.h"

  #ifndef NULL
    #define NULL 0
  #endif

extern BITMAP *screen_buffer;
extern unsigned char game_pal[768];
extern FONT *font;
extern volatile int global_delay;
extern BITMAP *court;
extern BITMAP *logo;
extern BITMAP *logo_c;
extern volatile int game_difficulty_level; //0 = easy; 1 = normal; 2 = hard;
extern volatile int game_player1; //0 = human; 1 = computer;
extern volatile int game_player2; //0 = human; 1 = computer;
extern BITMAP *bar_left;
extern BITMAP *bar_right;
extern BITMAP *ball[2];
extern volatile int game_ball_sprite;

#endif