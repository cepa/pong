#ifndef __MELODY_H__
  #define __MELODY_H__

typedef struct
{
  unsigned long int len;
  unsigned long int pos;
  unsigned long int size;
  unsigned int *data;
} MELODY;

MELODY *create_melody(unsigned long int len);
void destroy_melody(MELODY *mel);
void play_melody(MELODY *mel,int loop);

#endif