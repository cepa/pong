#include "gfx13h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_bmp(char *filename,BITMAP *bm,unsigned char *palette)
{
  FILE *file = NULL;
  BMP_HEADER hdr;
  int i;
  int nullbytes = 0;
  int has_nullbytes = 0;
  long int x,y;

  if(!filename || !bm || !palette)
    return 0;

  if(!(file = fopen(filename,"rb")))
    return 0;

  fseek(file,0,SEEK_SET);
  fread(&hdr,sizeof(BMP_HEADER),1,file);

  if(strncmp(hdr.type,"BM",2) != 0)
  {
    fclose(file);
    return 0;
  }

  for(i = 0; i < 256; i++)
  {
    palette[i * 3] = hdr.palette[i * 4 + 2] / 4;
    palette[i * 3 + 1] = hdr.palette[i * 4 + 1] / 4;
    palette[i * 3 + 2] = hdr.palette[i * 4] / 4;
  }

  bm->w = hdr.width;
  bm->h = hdr.height;
  bm->size = bm->w * bm->h;

  if(bm->data)
    free(bm->data);

  if(!(bm->data = (unsigned char *)malloc(bm->size)))
  {
    fclose(file);
    return 0;
  }

  memset(bm->data,0,bm->size);

  if((bm->w / 4) * 4 != bm->w)
  {
    nullbytes = (bm->w / 4) * 4;
    nullbytes = bm->w - nullbytes;
    nullbytes = 4 - nullbytes;
    has_nullbytes = 1;
  }

  for(y = bm->h - 1; y >= 0; y--)
  {
    for(x = 0; x < bm->w; x++)
    {
      unsigned char c = 0;
      fread(&c,1,1,file);
      put_pixel(bm,x,y,c);
    }
    if(has_nullbytes)
      for(i = 0; i < nullbytes; i++)
	fgetc(file);
  }

  fclose(file);

  return 1;
}

int save_bmp(char *filename,BITMAP *bm,unsigned char *palette)
{
  FILE *file = NULL;
  BMP_HEADER hdr;
  int i = 0;
  int nullbytes = 0;
  long int x,y;
  int has_nullbytes = 0;

  if(!filename || !bm || !bm->data || !palette)
    return 0;

  if(!(file = fopen(filename,"wb")))
    return 0;

  if((bm->w / 4) * 4 != bm->w)
  {
    nullbytes = (bm->w / 4) * 4;
    nullbytes = bm->w - nullbytes;
    nullbytes = 4 - nullbytes;
    has_nullbytes = 1;
  }

  strncpy(hdr.type,"BM",2);
  hdr.filesize = sizeof(BMP_HEADER) + (((bm->w / 4) * 4 == bm->w) ? bm->size : ((bm->w / 4) * 4 + 4) * bm->h);
  hdr.reserved1 = 0;
  hdr.reserved2 = 0;
  hdr.dataoffset = sizeof(BMP_HEADER);
  hdr.infosize = 40;
  hdr.width = bm->w;
  hdr.height = bm->h;
  hdr.planes = 1; //?
  hdr.bpp = 8;
  hdr.compression = 0;
  hdr.datasize = bm->size + nullbytes * bm->h; //?
  hdr.xppm = 0;
  hdr.yppm = 0;
  hdr.usedcolors = 256; //?
  hdr.importantcolor = 0;

  for(i = 0; i < 256; i++)
  {
    hdr.palette[i * 4 + 3] = 0;
    hdr.palette[i * 4 + 2] = palette[i * 3] * 4;
    hdr.palette[i * 4 + 1] = palette[i * 3 + 1] * 4;
    hdr.palette[i * 4] = palette[i * 3 + 2] * 4;
  }

  fseek(file,0,SEEK_SET);
  fwrite(&hdr,sizeof(BMP_HEADER),1,file);

  for(y = bm->h - 1; y >= 0; y--)
  {
    unsigned char c = 0;
    for(x = 0; x < bm->w; x++)
    {
      c = get_pixel(bm,x,y);
      fwrite(&c,1,1,file);
    }
    c = 0;
    if(has_nullbytes)
      fwrite(&c,1,nullbytes,file);
  }

  fclose(file);

  return 1;
}


