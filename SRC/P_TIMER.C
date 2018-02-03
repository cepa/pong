#include "gstudio.h"
#include "p_global.h"

volatile int __ball_counter = 0;

void timer()
{
  global_delay = 1;

  __ball_counter++;
  if(__ball_counter > 15)
  {
    __ball_counter = 0;

    game_ball_sprite++;
    if(game_ball_sprite > 1)
      game_ball_sprite = 0;
  }
}
