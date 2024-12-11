#ifndef __SORT__
#define __SORT__

// c includes
#include <stdlib.h>

// local includes
#include "vector.h"

int comp_int64_t(const void* a, const void* b) {
    int64_t arg1 = *(const int64_t*)a;
    int64_t arg2 = *(const int64_t*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void sort(vector *v) {
  // modify this later
  qsort(v->data, v->curr_size, sizeof(int64_t), comp_int64_t);
}
#endif
