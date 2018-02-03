#ifndef __BITMAP_H__
  #define __BITMAP_H__

typedef struct
{
  unsigned int w,h,size;
  unsigned char *data;
} BITMAP;

extern BITMAP *screen;
extern volatile unsigned char bitmap_transparent_color;

BITMAP *create_bitmap(unsigned int w,unsigned int h);
void destroy_bitmap(BITMAP *bm);
int create_scrbm();
void destroy_scrbm();
void clear_bitmap(BITMAP *bm,unsigned char c);
void put_pixel(BITMAP *bm,unsigned int x,unsigned int y,unsigned char c);
unsigned char get_pixel(BITMAP *bm,unsigned int x,unsigned int y);
void hline(BITMAP *bm,unsigned int x1,unsigned int y,unsigned int x2,unsigned char c);
void vline(BITMAP *bm,unsigned int x,unsigned int y1,unsigned int y2,unsigned char c);
void rect(BITMAP *bm,unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned char c);
void rectfill(BITMAP *bm,unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned char c);
void blit(BITMAP *src,BITMAP *dest,int _sx,int _sy,int _dx,int _dy,unsigned int w,unsigned int h);
void __blit(BITMAP *src,BITMAP *dest,int _sx,int _sy,int _dx,int _dy,unsigned int w,unsigned int h);
void masked_blit(BITMAP *src,BITMAP *dest,int _sx,int _sy,int _dx,int _dy,unsigned int w,unsigned int h);
void __masked_blit(BITMAP *src,BITMAP *dest,int _sx,int _sy,int _dx,int _dy,unsigned int w,unsigned int h);
void draw_screen_buffer(BITMAP *scrbuf);

#endif