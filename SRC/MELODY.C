#include "melody.h"
#include "sound.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

MELODY *create_melody(unsigned long int len)
{
  MELODY *mel = NULL;

  if(!(mel = (MELODY *)malloc(sizeof(MELODY))))
    return NULL;

  memset(mel,0,sizeof(MELODY));

  if(!(mel->data = (unsigned int *)malloc(len * 2 * sizeof(unsigned int))))
  {
    destroy_melody(mel);
    return NULL;
  }

  mel->len = len;
  mel->size = len * 2 * sizeof(unsigned int);
  mel->pos = 0;

  memset(mel->data,0,mel->size);

  return mel;
}

void destroy_melody(MELODY *mel)
{
  if(mel)
  {
    if(mel->data)
      free(mel->data);
    free(mel);
  }
  mel = NULL;
}

void play_melody(MELODY *mel,int loop)
{
  unsigned int freq = 0,time = 0;

  if(!mel || !mel->data)
    return;

  if(sound_done == 1)
  {
    if(!loop)
    {
      if(mel->pos < mel->len)
      {
	freq = mel->data[mel->pos * 2];
	time = mel->data[mel->pos * 2 + 1];
	mel->pos++;
	if(freq <= 20)
	{
	  sound_delay(MS2T(time));
	  return;
	}
	beep(HZ2D(freq),MS2T(time));
      }
    }
    else
    {
      if(mel->pos >= mel->len)
	mel->pos = 0;
      freq = mel->data[mel->pos * 2];
      time = mel->data[mel->pos * 2 + 1];
      mel->pos++;
      if(freq <= 20)
      {
	sound_delay(MS2T(time));
	return;
      }
      beep(HZ2D(freq),MS2T(time));
    }
  }
}

