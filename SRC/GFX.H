#ifndef __GFX_H__
  #define __GFX_H__

  #include "bitmap.h"

int load_gfx(char *filename,BITMAP *bm);
int save_gfx(char *filename,BITMAP *bm);

#endif