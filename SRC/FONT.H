#ifndef __FONT_H__
  #define __FONT_H__

  #include "bitmap.h"

typedef struct
{
  unsigned char ascii;
  int width;
  unsigned long int offset;
} FONT_CHAR;

typedef struct
{
  unsigned char signs;
  unsigned long datasize;
  FONT_CHAR info[256];
  unsigned char *data;
  int height;
} FONT;

FONT *create_font();
void destroy_font(FONT *font);
void put_text(BITMAP *bm,FONT *font,unsigned int x,unsigned int y,unsigned char c,const char *str);
void put_text_center(BITMAP *bm,FONT *font,unsigned int x,unsigned int y,unsigned char c,const char *str);
void put_text_right(BITMAP *bm,FONT *font,unsigned int x,unsigned int y,unsigned char c,const char *str);
int text_height(FONT *font);
int text_width(FONT *font,char *str);

#endif
