// Manmeet Singh - msingh11@@ucsc.edu
// $Id$:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "inssort.h"

void inssort (void *base, size_t nelem, size_t size,
              int(*compar) (const void *, const void *)){
  size_t sorted;
  for (sorted = 1; sorted < nelem; ++sorted){
    size_t slot = sorted;
    void *copy = malloc(size);
    memcpy (copy, (char*) (base + slot*size), size);

    for (;slot > 0; --slot){
      int cmp = compar (copy, base + ((slot -1 )*size));
      if (cmp > 0) break;

      memcpy((base+slot*size), base + ((slot -1 )*size), size);
    }
    memcpy ((base + slot*size), copy, size);
    free(copy);
  }
}

