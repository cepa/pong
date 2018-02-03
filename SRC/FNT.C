#include "fnt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_fnt(char *filename,FONT *font)
{
  FILE *file = NULL;
  char buf[4];

  if(!filename || !font)
    return 0;

  if(!(file = fopen(filename,"rb")))
    return 0;

  fseek(file,0,SEEK_SET);

  fread(buf,1,3,file);

  if(strncmp(buf,"FNT",3) != 0)
  {
    fclose(file);
    return 0;
  }

  fread(&font->signs,1,sizeof(font->signs),file);
  fread(&font->height,1,sizeof(font->height),file);
  fread(&font->datasize,1,sizeof(font->datasize),file);
  fread(font->info,1,sizeof(font->info),file);

  if(font->data)
    free(font->data);

  if(!(font->data = (unsigned char *)malloc(font->datasize)))
  {
    fclose(file);
    return 0;
  }

  memset(font->data,0,font->datasize);

  fread(font->data,1,font->datasize,file);

  fclose(file);

  return 1;
}

int save_fnt(char *filename,FONT *font)
{
  FILE *file = NULL;

  if(!filename || !font || !font->data)
    return 0;

  if(!(file = fopen(filename,"wb")))
    return 0;

  fwrite("FNT",1,3,file);
  fwrite(&font->signs,1,sizeof(font->signs),file);
  fwrite(&font->height,1,sizeof(font->height),file);
  fwrite(&font->datasize,1,sizeof(font->datasize),file);
  fwrite(font->info,1,sizeof(font->info),file);
  fwrite(font->data,1,font->datasize,file);

  fclose(file);

  return 1;
}


