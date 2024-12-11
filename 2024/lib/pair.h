#ifndef __PAIR_H__
#define __PAIR_H__

#include <stdint.h>
#include <stdlib.h>

typedef struct pair {
  char type1, type2;
  void* f;
  void* s;
} pair;

void init_pair(pair** p, char type1, char type2);
void clear_pair(pair* p);
void set_first(pair* p, void* e);
void set_second(pair* p, void* e);
void* get_first(pair* p);
void* get_second(pair* p);
void show_pair(pair* p);

#endif /* ifndef __PAIR__ */
