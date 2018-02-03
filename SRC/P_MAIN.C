#include "gstudio.h"
#include "p_global.h"
#include "p_timer.h"
#include "p_menu1.h"
#include <stdio.h>

void install()
{
  if(!load_pal("data/game.pal",game_pal))
  {
    printf("Error - Couldn't load game palette !\n");
    exit(-1);
  }

  if(!(font = create_font()))
  {
    printf("Error - Couldn't create FONT structure !\n");
    exit(-1);
  }

  if(!load_fnt("data/font.fnt",font))
  {
    printf("Error - Couldn't load game font !\n");
    exit(-1);
  }

  if(!(screen_buffer = create_bitmap(320,200)))
  {
    printf("Error - Couldn't create screen buffer !\n");
    exit(-1);
  }

  if(!(court = create_bitmap(1,1)))
  {
    close13h();
    printf("Error - Couldn't create bitmap !\n");
    exit(-1);
  }

  if(!load_gfx("data/court.gfx",court))
  {
    close13h();
    printf("Error - Couldn't load bitmap !\n");
    exit(-1);
  }

  if(!(logo = create_bitmap(1,1)))
  {
    close13h();
    printf("Error - Couldn't create bitmap !\n");
    exit(-1);
  }

  if(!load_gfx("data/pong.gfx",logo))
  {
    close13h();
    printf("Error - Couldn't load bitmap !\n");
    exit(-1);
  }

  if(!(logo_c = create_bitmap(1,1)))
  {
    close13h();
    printf("Error - Couldn't create bitmap !\n");
    exit(-1);
  }

  if(!load_gfx("data/pong_c.gfx",logo_c))
  {
    close13h();
    printf("Error - Couldn't load bitmap !\n");
    exit(-1);
  }

  if(!(bar_left = create_bitmap(1,1)))
  {
    close13h();
    printf("Error - Couldn't create bitmap !\n");
    exit(-1);
  }

  if(!load_gfx("data/bar_l.gfx",bar_left))
  {
    close13h();
    printf("Error - Couldn't load bitmap !\n");
    exit(-1);
  }

  if(!(bar_right = create_bitmap(1,1)))
  {
    close13h();
    printf("Error - Couldn't create bitmap !\n");
    exit(-1);
  }

  if(!load_gfx("data/bar_r.gfx",bar_right))
  {
    close13h();
    printf("Error - Couldn't load bitmap !\n");
    exit(-1);
  }

  if(!(ball[0] = create_bitmap(1,1)))
  {
    close13h();
    printf("Error - Couldn't create bitmap !\n");
    exit(-1);
  }

  if(!load_gfx("data/ball1.gfx",ball[0]))
  {
    close13h();
    printf("Error - Couldn't load bitmap !\n");
    exit(-1);
  }

  if(!(ball[1] = create_bitmap(1,1)))
  {
    close13h();
    printf("Error - Couldn't create bitmap !\n");
    exit(-1);
  }

  if(!load_gfx("data/ball2.gfx",ball[1]))
  {
    close13h();
    printf("Error - Couldn't load bitmap !\n");
    exit(-1);
  }

  init13h();
  install_keyboard();
  install_timer(MS2D(10),timer);
  set_palette(game_pal);
  clear_bitmap(screen_buffer,0);
  draw_screen_buffer(screen_buffer);
}

void uninstall()
{
  destroy_bitmap(ball[1]);
  destroy_bitmap(ball[0]);
  destroy_bitmap(bar_left);
  destroy_bitmap(bar_right);
  destroy_bitmap(logo_c);
  destroy_bitmap(logo);
  destroy_bitmap(court);
  destroy_bitmap(screen_buffer);
  destroy_font(font);
  remove_timer();
  remove_keyboard();
  close13h();
}

int main(int argc,char **argv)
{
  install();

  game_menu1();

  uninstall();

  printf("PONG Clone\nCopyright (c) By CEPA 2004\ncepa@o2.pl\nwww.cepa.end.pl\n");

  return 0;
}
