#ifndef __GFX13H_H__
  #define __GFX13H_H__

  #include "pal.h"
  #include "bitmap.h"
  #include "gfx.h"
  #include "bmp.h"
  #include "font.h"

int init13h();
void close13h();
void vga_put_pixel(unsigned int x,unsigned int y,unsigned char color);
unsigned char vga_get_pixel(unsigned int x,unsigned int y);
void clear_screen(unsigned char color);
void set_color(unsigned char c,unsigned char r,unsigned char g,unsigned char b);
void get_color(unsigned char c,unsigned char *r,unsigned char *g,unsigned char *b);
void set_palette(unsigned char *palette);
void get_palette(unsigned char *palette);
void vsync();

#endif
