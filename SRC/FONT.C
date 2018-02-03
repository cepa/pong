#include "gfx13h.h"
#include <stdio.h>
#include <stdlib.h>

FONT *create_font()
{
  FONT *font = NULL;

  if(!(font = (FONT *)malloc(sizeof(FONT))))
    return NULL;

  memset(font,0,sizeof(FONT));

  return font;
}

void destroy_font(FONT *font)
{
  if(font)
  {
    if(font->data);
      free(font->data);
  }
  font = NULL;
}

void __put_char(BITMAP *bm,FONT *font,unsigned int x,unsigned int y,unsigned char c,char ascii)
{
  unsigned int xx = 0,yy = 0;
  unsigned long int offset = 0;

  if(font->info[ascii].ascii != ascii || font->info[ascii].offset == 0)
    return;

  offset = font->info[ascii].offset;

  for(yy = 0; yy < font->height; yy++)
  {
    for(xx = 0; xx < font->info[ascii].width; xx++)
    {
      if(font->data[offset] == 1)
	put_pixel(bm,xx + x,yy + y,c);
      offset++;
    }
  }
}

void put_text(BITMAP *bm,FONT *font,unsigned int x,unsigned int y,unsigned char c,const char *str)
{
  int tx = x;

  if(!font || !bm)
    return;

  while(*str)
  {
    __put_char(bm,font,tx,y,c,*str);
    tx += font->info[*str].width + 1;
    str++;
  }
}

void put_text_center(BITMAP *bm,FONT *font,unsigned int x,unsigned int y,unsigned char c,const char *str)
{
  int tw = text_width(font,str);
  put_text(bm,font,x - tw / 2,y,c,str); 
}

void put_text_right(BITMAP *bm,FONT *font,unsigned int x,unsigned int y,unsigned char c,const char *str)
{
  int tw = text_width(font,str);
  put_text(bm,font,x - tw,y,c,str);
}

int text_height(FONT *font)
{
  if(!font)
    return 0;
    
  return font->height;
}

int text_width(FONT *font,char *str)
{
  int w = 0;
  
  if(!font || !str)
    return 0;
  
  while(*str)
  {
    w += font->info[*str].width + 1;
    str++;
  }
  
  return w;
}

