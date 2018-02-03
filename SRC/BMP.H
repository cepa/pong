#ifndef __BMP_H__
  #define __BMP_H__

  #include "bitmap.h"

/*
  "Important thing is that the number of bytes in one row
  must always be adjusted to fit into the border of a
  multiple of four" !!!!
*/

typedef struct
{
  //file header
  char type[2];
  unsigned long int filesize;
  short int reserved1;
  short int reserved2;
  unsigned long int dataoffset;
  //info header
  unsigned long int infosize;
  unsigned long int width;
  unsigned long int height;
  short int planes;
  short int bpp;
  unsigned long int compression;
  unsigned long int datasize;
  unsigned long int xppm;
  unsigned long int yppm;
  unsigned long int usedcolors;
  unsigned long int importantcolor;
  unsigned char palette[1024];
} BMP_HEADER;

int load_bmp(char *filename,BITMAP *bm,unsigned char *palette);
int save_bmp(char *filename,BITMAP *bm,unsigned char *palette);

#endif