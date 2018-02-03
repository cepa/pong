#include "gstudio.h"
#include "p_global.h"

int menu2_menu_index = 1;
int menu2_done = 0;
int menu2_can_update = 1;

void menu2_update()
{
  int tw1,tw2,tw3;
  int tx1,tx2,tx3;

  blit(court,screen_buffer,0,0,0,0,320,200);
  masked_blit(logo,screen_buffer,0,0,160 - logo->w / 2,10,logo->w,logo->h);

  tw1 = text_width(font,"EASY");
  tw2 = text_width(font,"NORMAL");
  tw3 = text_width(font,"HARD");

  tx2 = 160 - tw2 / 2;
  tx1 = tx2 - 20 - tw1;
  tx3 = 160 + tw2 / 2 + 20;

  put_text(screen_buffer,font,tx1,90,58,"EASY");
  put_text(screen_buffer,font,tx2,90,58,"NORMAL");
  put_text(screen_buffer,font,tx3,90,58,"HARD");

  switch(menu2_menu_index)
  {
    case 0: put_text(screen_buffer,font,tx1,90,160,"EASY"); break;
    case 1: put_text(screen_buffer,font,tx2,90,160,"NORMAL"); break;
    case 2: put_text(screen_buffer,font,tx3,90,160,"HARD"); break;
  }

  draw_screen_buffer(screen_buffer);
}

int game_menu2()
{
  int ret = 0;

  while(!menu2_done)
  {
    if(global_delay)
    {
      if(key[KEY_ESC])
      {
	menu2_done = 1;
	ret = 0;
	beep(100,100);
      }

      if(key[KEY_ENTER])
      {
	game_difficulty_level = menu2_menu_index;
	ret = 1;
	menu2_done = 1;

	//timer_delay(MS2T(100));
	beep(100,100);
      }

      if(key[KEY_LEFT])
      {
	menu2_menu_index--;
	if(menu2_menu_index < 0)
	  menu2_menu_index = 2;
	menu2_can_update = 1;
	timer_delay(MS2T(100));
	beep(100,100);
      }

      if(key[KEY_RIGHT])
      {
	menu2_menu_index++;
	if(menu2_menu_index > 2)
	  menu2_menu_index = 0;
	menu2_can_update = 1;
	timer_delay(MS2T(100));
	beep(100,100);
      }

      if(menu2_can_update)
      {
	menu2_update();
	menu2_can_update = 0;
      }
    }
  }

  menu2_done = 0;
  menu2_menu_index = 1;
  menu2_can_update = 1;

  timer_delay(MS2T(200));

  return ret;
}

