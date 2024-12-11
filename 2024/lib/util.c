#ifndef __UTIL__
#define __UTIL__

// c includes
#include <assert.h>
#include <stdint.h>
#include <string.h>

// local includes
#include "pair.h"

void swap(void *a, void *b, uint64_t size) {
    unsigned char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int8_t comp_int64_t(int64_t a, int64_t b) {
  if(a > b) return 1;
  if(a < b) return -1;
  return 0;
}

int8_t comp_char(char a, char b) {
  if(a > b) return 1;
  if(a < b) return -1;
  return 0;
}

int8_t comp_pair(pair a, pair b) {
  assert(a.type1 == b.type1 && a.type2 == b.type2);

  int8_t ret_f;
  if(a.type1 == 'I') {
    ret_f = comp_int64_t(*((int64_t*) a.f), *((int64_t*) b.f));
  } else if(a.type1 == 'c') {
    ret_f = comp_char(*((char*) a.f), *((char*) b.f)); 
  }

  if(ret_f != 0) return ret_f;

  int8_t ret_s;
  if(a.type2 == 'I') {
    ret_s = comp_int64_t(*((int64_t*) a.s), *((int64_t*) b.s));
  } else if(a.type2 == 'c') {
    ret_s = comp_char(*((char*) a.s), *((char*) b.s)); 
  }
  return ret_s;
}

int8_t comp(void* a, void* b, char type) {
  if(type == 'I') return comp_int64_t(*((int64_t*) a), *((int64_t*) b));
  if(type == 'c') return comp_char(*((char*) a), *((char*) b));
  if(type == 'p') return comp_pair(*((pair*) a), *((pair*) b));

  return -2;
}

#endif
