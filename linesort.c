// Manmeet Singh - msingh11@@ucsc.edu
// $Id$:

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inssort.h"

#define SIZE 4096

int strstrcmp (const void *this, const void *that) {
  char **thisstr = (char**) this;
  char **thatstr = (char**) that;
  return strcmp (*thisstr, *thatstr);
}

int main (void){
  char line[SIZE];
  char **buff = malloc (sizeof(char*) * SIZE);
  int count = 0;
  while (fgets(line, SIZE, stdin)){
    if (feof(stdin)) break;
    buff[count] = strdup(line);
    count ++;
    if (count == SIZE) break;
  }

  inssort(buff, count, sizeof(buff[0]), strstrcmp);
  int i;
  for (i = 0; i < count ; i++) {
    printf("\t%s", buff[i]);
  }
  for(count=0;count<0x1000;count++) {
    free(buff[count]);
  }
  free(buff);
  return 0;
}

