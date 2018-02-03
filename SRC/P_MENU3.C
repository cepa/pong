#include "gstudio.h"
#include "p_global.h"

int menu3_can_update = 1;
int menu3_done = 0;
int menu3_menu1_index = 0;
int menu3_menu2_index = 1;
int menu3_menu_index = 1;

void menu3_update()
{
  blit(court,screen_buffer,0,0,0,0,320,200);
  masked_blit(logo,screen_buffer,0,0,160 - logo->w / 2,10,logo->w,logo->h);

  put_text(screen_buffer,font,60,90,32,"PLAYER 1");
  put_text(screen_buffer,font,60,100,58,"HUMAN");
  put_text(screen_buffer,font,60,110,58,"COMPUTER");

  put_text_right(screen_buffer,font,260,90,32,"PLAYER 2");
  put_text_right(screen_buffer,font,260,100,58,"HUMAN");
  put_text_right(screen_buffer,font,260,110,58,"COMPUTER");

  switch(menu3_menu1_index)
  {
    case 0: put_text(screen_buffer,font,60,100,160,"HUMAN"); break;
    case 1: put_text(screen_buffer,font,60,110,160,"COMPUTER"); break;
  }

  switch(menu3_menu2_index)
  {
    case 0: put_text_right(screen_buffer,font,260,100,160,"HUMAN"); break;
    case 1: put_text_right(screen_buffer,font,260,110,160,"COMPUTER"); break;
  }

  draw_screen_buffer(screen_buffer);
}

void game_menu3()
{
  while(!menu3_done)
  {
    if(global_delay)
    {
      if(key[KEY_ESC])
      {
	menu3_done = 1;
	beep(100,100);
      }

      if(key[KEY_LEFT])
      {
	menu3_menu_index--;
	if(menu3_menu_index < 0)
	  menu3_menu_index = 1;
	menu3_can_update = 1;
	timer_delay(MS2T(100));
	beep(100,100);
      }

      if(key[KEY_RIGHT])
      {
	menu3_menu_index++;
	if(menu3_menu_index > 1)
	  menu3_menu_index = 0;
	menu3_can_update = 1;
	timer_delay(MS2T(100));
	beep(100,100);
      }

      if(key[KEY_UP])
      {
	switch(menu3_menu_index)
	{
	  case 0:
	  {
	    menu3_menu1_index--;
	    if(menu3_menu1_index < 0)
	      menu3_menu1_index = 1;
	  } break;

	  case 1:
	  {
	    menu3_menu2_index--;
	    if(menu3_menu2_index < 0)
	      menu3_menu2_index = 1;
	  } break;
	}

	menu3_can_update = 1;
	timer_delay(MS2T(100));
	beep(100,100);
      }

      if(key[KEY_DOWN])
      {
	switch(menu3_menu_index)
	{
	  case 0:
	  {
	    menu3_menu1_index++;
	    if(menu3_menu1_index > 1)
	      menu3_menu1_index = 0;
	  } break;

	  case 1:
	  {
	    menu3_menu2_index++;
	    if(menu3_menu2_index > 1)
	      menu3_menu2_index = 0;
	  } break;
	}

	menu3_can_update = 1;
	timer_delay(MS2T(100));
	beep(100,100);
      }

      if(menu3_can_update)
      {
	menu3_update();
	menu3_can_update = 0;
      }
    }
  }

  game_player1 = menu3_menu1_index;
  game_player2 = menu3_menu2_index;

  menu3_can_update = 1;
  menu3_done = 0;
  menu3_menu1_index = 0;
  menu3_menu2_index = 1;
  menu3_menu_index = 1;

  timer_delay(MS2T(200));
}