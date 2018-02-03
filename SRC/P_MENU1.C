#include "gstudio.h"
#include "p_global.h"
#include "p_game.h"
#include "p_menu2.h"

int menu1_done = 0;
int menu1_can_update = 1;
int menu1_menu_index = 0;

void menu1_update()
{
  blit(court,screen_buffer,0,0,0,0,320,200);
  masked_blit(logo,screen_buffer,0,0,160 - logo->w / 2,10,logo->w,logo->h);

  put_text_center(screen_buffer,font,160,90,58,"START");
  put_text_center(screen_buffer,font,160,100,58,"PLAYERS");
  put_text_center(screen_buffer,font,160,110,58,"ABOUT");
  put_text_center(screen_buffer,font,160,120,58,"EXIT");

  switch(menu1_menu_index)
  {
    case 0: put_text_center(screen_buffer,font,160,90,160,"START"); break;
    case 1: put_text_center(screen_buffer,font,160,100,160,"PLAYERS"); break;
    case 2: put_text_center(screen_buffer,font,160,110,160,"ABOUT"); break;
    case 3: put_text_center(screen_buffer,font,160,120,160,"EXIT"); break;
  }

  draw_screen_buffer(screen_buffer);
}

void game_menu1()
{
  while(!menu1_done)
  {
    if(global_delay)
    {
      if(key[KEY_ESC])
      {
	menu1_done = 1;
	beep(100,100);
      }

      if(key[KEY_ENTER])
      {
	beep(100,100);
	timer_delay(MS2T(100));

	switch(menu1_menu_index)
	{
	  case 0:
	  {
	    if(game_menu2() == 1)
	      game_play();
	  } break; //start
	  case 1: game_menu3(); break; //players
	  case 2: game_about(); break; //about
	  case 3: menu1_done = 1; break; //exit
	}

	menu1_can_update = 1;
      }

      if(key[KEY_UP])
      {
	menu1_menu_index--;
	if(menu1_menu_index < 0)
	  menu1_menu_index = 3;
	menu1_can_update = 1;
	timer_delay(MS2T(100));
	beep(100,100);
      }

      if(key[KEY_DOWN])
      {
	menu1_menu_index++;
	if(menu1_menu_index > 3)
	  menu1_menu_index = 0;
	menu1_can_update = 1;
	timer_delay(MS2T(100));
	beep(100,100);
      }

      if(menu1_can_update)
      {
	menu1_update();
	menu1_can_update = 0;
      }

      global_delay = 0;
    }
  }
}
