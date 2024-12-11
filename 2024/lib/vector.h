#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct vector {
  void* data;
  uint64_t curr_size;
  uint64_t max_size;
  char type;
} vector;

void init_vector(vector** v, char type);
void clear_vector(vector *v);
void push_back(vector* v, void* e);
void pop_back(vector *v);
void* get(vector *v, uint64_t i);
void set(vector *v, uint64_t i, void* e);
uint64_t size(vector *v);
void insert(vector *v, void* e, uint64_t i);
void erase(vector *v, uint64_t i);
void show_vector(vector *v);

#endif
