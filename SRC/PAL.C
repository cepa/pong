#include "gfx13h.h"
#include <stdio.h>

int load_pal(char *filename,unsigned char *palette)
{
  FILE *file = NULL;

  if(!palette || !filename)
    return 0;

  if(!(file = fopen(filename,"rb")))
    return 0;

  fseek(file,0,SEEK_SET);
  fread(palette,1,768,file);

  fclose(file);

  return 1;
}

int save_pal(char *filename,unsigned char *palette)
{
  FILE *file = NULL;

  if(!palette || !filename)
    return 0;

  if(!(file = fopen(filename,"wb")))
    return 0;

  fseek(file,0,SEEK_SET);
  fwrite(palette,1,768,file);

  fclose(file);

  return 1;
}

