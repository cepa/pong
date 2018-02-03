#include "gstudio.h"
#include "p_global.h"
#include <stdio.h>
#include <stdlib.h>

int game_done = 0;
int game_bar_l_y = 85;
int game_bar_r_y = 85;
int game_logo_x = 10;
float game_ball_x = 157;
float game_ball_y = 97;
int game_player1_points = 0;
int game_player2_points = 0;
int game_ball_speed = 2;
float game_ball_vx = 0.5;
float game_ball_vy = 0.5;
int game_bar_v = 0;
int game_logo = 1;
int game_limit = 10;
int game_winner = 0;

void game_update()
{
  BITMAP *_ball = ball[game_ball_sprite];
  char buf[30];

  blit(court,screen_buffer,0,0,0,0,320,200);

  if(game_logo == 1)
    masked_blit(logo,screen_buffer,0,0,160 - logo->w / 2,game_logo_x,logo->w,logo->h);
  else
    masked_blit(logo_c,screen_buffer,0,0,160 - logo->w / 2,game_logo_x,logo->w,logo->h);

  masked_blit(bar_left,screen_buffer,0,0,8,game_bar_l_y,bar_left->w,bar_left->h);
  masked_blit(bar_right,screen_buffer,0,0,306,game_bar_r_y,bar_right->w,bar_right->h);

  put_text(screen_buffer,font,60,4,32,"PLAYER 2");
  put_text_right(screen_buffer,font,260,4,32,"PLAYER 1");

  sprintf(buf,"POINTS: %d",game_player2_points);
  put_text(screen_buffer,font,60,14,58,buf);

  sprintf(buf,"POINTS: %d",game_player1_points);
  put_text_right(screen_buffer,font,260,14,58,buf);

  switch(game_player2)
  {
    case 0: put_text(screen_buffer,font,60,191,32,"HUMAN"); break;
    case 1: put_text(screen_buffer,font,60,191,32,"COMPUTER"); break;
  }

  switch(game_player1)
  {
    case 0: put_text_right(screen_buffer,font,260,191,32,"HUMAN"); break;
    case 1: put_text_right(screen_buffer,font,260,191,32,"COMPUTER"); break;
  }

  masked_blit(_ball,screen_buffer,0,0,(int)game_ball_x,(int)game_ball_y,_ball->w,_ball->h);

  if(game_winner == 1)
    put_text_center(screen_buffer,font,160,90,160,"PLAYER 1 IS WINNER !!!");
  if(game_winner == 2)
    put_text_center(screen_buffer,font,160,90,160,"PLAYER 2 IS WINNER !!!");

  draw_screen_buffer(screen_buffer);
}

void game_reset_ball()
{
  game_ball_x = 157;
  game_ball_y = 97;

  switch(rand() % 4)
  {
    case 0:
      game_ball_vx = 0.5;
      game_ball_vy = 0.5;
      break;

    case 1:
      game_ball_vx = -0.5;
      game_ball_vy = 0.5;
      break;

    case 2:
      game_ball_vx = 0.5;
      game_ball_vy = -0.5;
      break;

    case 3:
      game_ball_vx = -0.5;
      game_ball_vy = -0.5;
      break;
  }
}

void game_move_ball()
{
  game_ball_x += game_ball_vx * game_ball_speed;
  game_ball_y += game_ball_vy * game_ball_speed;

  if(game_ball_x >= 300 && game_ball_y > game_bar_r_y && game_ball_y < game_bar_r_y + 31)
  {
    game_ball_x = 300;

    if(game_player1 == 0)
    {
      if(key[KEY_UP] || key[KEY_DOWN])
      {
	game_ball_vy += 0.3;
	if(game_ball_vy > 0.8)
	  game_ball_vy = 0.8;
      }
      else
	game_ball_vy = 0.5;
    }

    game_ball_vx = -game_ball_vx;
    beep(500,50);
  }

  if(game_ball_x <= 15 && game_ball_y > game_bar_l_y && game_ball_y < game_bar_l_y + 31)
  {
    game_ball_x = 15;

    if(game_player2 == 0)
    {
      if(key[KEY_Q] || key[KEY_A])
      {
	game_ball_vy += 0.3;
	if(game_ball_vy > 0.8)
	  game_ball_vy = 0.8;
      }
      else
	game_ball_vy = 0.5;
    }

    game_ball_vx = -game_ball_vx;
    beep(500,50);
  }

  if(game_ball_x < 0)
  {
    game_ball_x = 0;
    game_ball_vx = -game_ball_vx;

    if(game_ball_y > 58 && game_ball_y < 144)
      game_player1_points += 2;
    else
      game_player1_points++;
    game_ball_x = 320;
    game_ball_y = 200;
    game_update();
    beep(300,500);
    timer_delay(MS2T(500));
    if(game_player1_points >= game_limit)
    {
      game_done = 1;
      game_winner = 1;
    }
    else
      game_reset_ball();
  }

  if(game_ball_x > 314)
  {
    game_ball_x = 314;
    game_ball_vx = -game_ball_vx;

    if(game_ball_y > 58 && game_ball_y < 144)
      game_player2_points += 2;
    else
      game_player2_points++;
    game_ball_x = 320;
    game_ball_y = 200;
    game_update();
    beep(300,500);
    timer_delay(MS2T(500));
    if(game_player2_points >= game_limit)
    {
      game_done = 1;
      game_winner = 2;
    }
    else
      game_reset_ball();
  }

  if(game_ball_y < 3)
  {
    game_ball_y = 3;
    game_ball_vy = -game_ball_vy;
    beep(100,50);
  }

  if(game_ball_y > 192)
  {
    game_ball_y = 192;
    game_ball_vy = -game_ball_vy;
    beep(100,50);
  }
}

void game_computer()
{
  if(game_player1 == 1)
  {
    if(game_ball_y < game_bar_r_y + 5)
      game_bar_r_y -= game_bar_v;

    if(game_ball_y > game_bar_r_y + 26)
      game_bar_r_y += game_bar_v;

    if(game_bar_r_y < 3)
      game_bar_r_y = 3;

    if(game_bar_r_y > 166)
      game_bar_r_y = 166;
  }

  if(game_player2 == 1)
  {
    if(game_ball_y < game_bar_l_y + 5)
      game_bar_l_y -= game_bar_v;

    if(game_ball_y > game_bar_l_y + 26)
      game_bar_l_y += game_bar_v;

    if(game_bar_l_y < 3)
      game_bar_l_y = 3;

    if(game_bar_l_y > 166)
      game_bar_l_y = 166;
  }
}

void game_play()
{
  {
    int anim_done = 0;

    while(!anim_done)
    {
      if(global_delay)
      {
	if(game_logo_x >= 100 - logo->h / 2)
	  anim_done = 1;

	game_update();

	game_logo_x++;
      }
    }

    game_logo = 0;
  }

  switch(game_difficulty_level)
  {
    case 0:
      game_ball_speed = 3;
      game_bar_v = 1;
      game_limit = 10;
    break;

    case 1:
      game_ball_speed = 5;
      game_bar_v = 2;
      game_limit = 20;
    break;

    case 2:
      game_ball_speed = 6;
      game_bar_v = 3;
      game_limit = 30;
    break;
  }

  game_reset_ball();

  while(!game_done)
  {
    if(global_delay)
    {
      if(key[KEY_ESC])
      {
	game_done = 1;
	beep(100,100);
      }

      if(key[KEY_UP])
      {
	if(game_player1 == 0)
	{
	  game_bar_r_y -= 3;
	  if(game_bar_r_y < 3)
	    game_bar_r_y = 3;
	}
      }

      if(key[KEY_DOWN])
      {
	if(game_player1 == 0)
	{
	  game_bar_r_y += 3;
	  if(game_bar_r_y > 166)
	    game_bar_r_y = 166;
	}
      }

      if(key[KEY_Q])
      {
	if(game_player2 == 0)
	{
	  game_bar_l_y -= 3;
	  if(game_bar_l_y < 3)
	    game_bar_l_y = 3;
	}
      }

      if(key[KEY_A])
      {
	if(game_player2 == 0)
	{
	  game_bar_l_y += 3;
	  if(game_bar_l_y > 166)
	    game_bar_l_y = 166;
	}
      }

      game_move_ball();
      game_computer();
      game_update();

      global_delay = 0;
    }
  }

  if(game_winner > 0)
  {
    int anim_done = 0;

    game_logo = 1;
    game_ball_x = 320;
    game_ball_y = 200;

    while(!anim_done)
    {
      if(global_delay)
      {
	if(game_logo_x <= 10)
	  anim_done = 1;

	game_update();

	game_logo_x--;
      }
    }

    wait_for_any_key();
    beep(100,100);
  }

  game_done = 0;
  game_bar_l_y = 85;
  game_bar_r_y = 85;
  game_logo_x = 10;
  game_ball_x = 157;
  game_ball_y = 97;
  game_player1_points = 0;
  game_player2_points = 0;
  game_ball_speed = 0;
  game_ball_vx = 0.5;
  game_ball_vy = 0.5;
  game_bar_v = 0;
  game_logo = 1;
  game_limit = 10;
  game_winner = 0;

  timer_delay(MS2T(200));
}