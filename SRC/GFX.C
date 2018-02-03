#include "gfx13h.h"
#include <stdio.h>
#include <stdlib.h>

int load_gfx(char *filename,BITMAP *bm)
{
  FILE *file = NULL;

  if(!filename || !bm)
    return 0;

  if(!(file = fopen(filename,"rb")))
    return 0;

  fread(&bm->w,1,sizeof(bm->w),file);
  fread(&bm->h,1,sizeof(bm->h),file);
  fread(&bm->size,1,sizeof(bm->size),file);

  if(bm->data)
    free(bm->data);

  if(!(bm->data = (unsigned char *)malloc(bm->size)))
  {
    fclose(file);
    return 0;
  }

  memset(bm->data,0,bm->size);

  fread(bm->data,1,bm->size,file);

  fclose(file);

  return 1;
}

int save_gfx(char *filename,BITMAP *bm)
{
  FILE *file = NULL;

  if(!filename || !bm || !bm->data)
    return 0;

  if(!(file = fopen(filename,"wb")))
    return 0;

  fseek(file,0,SEEK_SET);
  fwrite(&bm->w,1,sizeof(bm->w),file);
  fwrite(&bm->h,1,sizeof(bm->h),file);
  fwrite(&bm->size,1,sizeof(bm->size),file);
  fwrite(bm->data,1,bm->size,file);

  fclose(file);

  return 1;
}


