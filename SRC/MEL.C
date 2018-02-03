#include "mel.h"
#include <stdio.h>
#include <stdlib.h>

int load_mel(char *filename,MELODY *mel)
{
  FILE *file = NULL;

  if(!filename || !mel)
    return 0;

  if(!(file = fopen(filename,"rb")))
    return 0;

  fseek(file,0,SEEK_SET);
  fread(&mel->len,1,sizeof(mel->len),file);
  fread(&mel->size,1,sizeof(mel->size),file);

  if(mel->data)
    free(mel->data);

  if(!(mel->data = (unsigned int *)malloc(mel->size)))
  {
    fclose(file);
    return 0;
  }

  memset(mel->data,0,mel->size);

  fread(mel->data,1,mel->size,file);

  fclose(file);

  return 1;
}

int save_mel(char *filename,MELODY *mel)
{
  FILE *file = NULL;

  if(!filename || !mel || !mel->data)
    return 0;

  if(!(file = fopen(filename,"wb")))
    return 0;

  fseek(file,0,SEEK_SET);
  fwrite(&mel->len,sizeof(mel->len),1,file);
  fwrite(&mel->size,sizeof(mel->size),1,file);
  fwrite(mel->data,1,mel->size,file);

  fclose(file);

  return 1;
}



