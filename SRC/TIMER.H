#ifndef __TIMER_H__
  #define __TIMER_H__

  #include "timer.h"

  #define HZ2D(hz) (1193181 / (hz + 1))
  #define MS2D(ms) (1193181 / (1000 / ms))
  #define MS2T(ms) (unsigned int)((float)ms / (((float)timer_d + 1) * (1000.0 / 1193181.0)))

extern volatile unsigned int timer_d;

void install_timer(unsigned int k,void (*proc)());
void remove_timer();
void timer_delay(unsigned int ticks);
void install_timer_delay_proc(void (*proc)());
void remove_timer_delay_proc();

#endif