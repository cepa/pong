#include "gstudio.h"
#include "p_global.h"

void about_update()
{
  blit(court,screen_buffer,0,0,0,0,320,200);
  masked_blit(logo,screen_buffer,0,0,160 - logo->w / 2,10,logo->w,logo->h);

  put_text_center(screen_buffer,font,160,90,32,"PONG CLONE");
  put_text_center(screen_buffer,font,160,100,32,"VERSION 1.0");
  put_text_center(screen_buffer,font,160,110,32,"COPYRIGHT BY CEPA 2004");
  put_text_center(screen_buffer,font,160,130,32,"THIS IS FREEWARE GAME");
  put_text_center(screen_buffer,font,160,140,32,"PONG IS USING GSTUDIO LIBRARY BY CEPA");
  put_text_center(screen_buffer,font,160,160,32,"WWW.CEPA.END.PL");

  draw_screen_buffer(screen_buffer);
}

void game_about()
{
  about_update();
  wait_for_any_key();
  beep(100,100);
  timer_delay(MS2T(200));
}