#ifndef __UTIL_H__
#define __UTIL_H__

// c includes
#include <assert.h>
#include <stdint.h>
#include <string.h>

// local includes
#include "pair.h"

void swap(void *a, void *b, uint64_t size);

int8_t comp_int64_t(int64_t a, int64_t b);
int8_t comp_char(char a, char b);
int8_t comp_pair(pair a, pair b);
int8_t comp(void* a, void* b, char type);

#endif
