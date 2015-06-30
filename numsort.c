// Manmeet Singh - msingh11@@ucsc.edu
// $Id$:


#include <stdio.h>
#include <stdlib.h>
#include "inssort.h"

int numcmp (const void *this, const void *that){
  double *thisint = (double*) this;
  double *thatint = (double*) that;
  return (*thisint > *thatint) - (*thisint < *thatint);
}

int main (void){
  double array[1024];
  int count = 0;
  for (;;){
    count++;
    if (count == (1024)) break;

    double num;
    int z = scanf("%lg", &num);
    if (z == EOF) break;
    if (z != 0) array[count] = num;
    else break;
  }
  inssort(array, count, sizeof (double), numcmp);
  int i;
  for (i = 0; i < count; i++) {
    printf("%20.15g\n",array[i]);
  }

  return 0;
}

