#ifndef __SOUND_H__
  #define __SOUND_H__

  #define OCTAVE_1 0
  #define OCTAVE_2 1
  #define OCTAVE_3 2
  #define OCTAVE_4 3
  #define OCTAVE_5 4
  #define OCTAVE_6 5
  #define OCTAVE_7 6

  #define TUNE_C 0
  #define TUNE_D 1
  #define TUNE_E 2
  #define TUNE_F 3
  #define TUNE_G 4
  #define TUNE_A 5
  #define TUNE_H 6

  #define TUNE(octave,tune) tunes[octave][tune]

static const unsigned int tunes[7][9] =
{
  //   C     D     E     F     G     A     H
  {   33,   37,   41,   44,   49,   55,   62}, //1
  {   65,   73,   82,   87,   98,  110,  123}, //2
  {  131,  147,  165,  175,  196,  220,  247}, //3
  {  262,  294,  330,  349,  392,  440,  494}, //4
  {  523,  587,  659,  698,  784,  880,  988}, //5
  { 1047, 1175, 1319, 1397, 1568, 1760, 1976}, //6
  { 2093, 2349, 2637, 2794, 3136, 3520, 3951}  //7
};

extern volatile unsigned int sound_counter;
extern volatile unsigned int sound_time;
extern volatile char sound_done;

void sound_timer();
void sound_on(unsigned int d);
void sound_of();
void __beep(unsigned int d,unsigned int ticks);
void beep(unsigned int hz,unsigned int ms);
void sound_delay(unsigned int ticks);

#endif
