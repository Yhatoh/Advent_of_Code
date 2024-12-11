#ifndef __PAIR__
#define __PAIR__

// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// local includes
#include "pair.h"

void init_pair(pair** p, char type1, char type2) {
  *p = (pair*) malloc(sizeof(pair));
  (*p)->f = NULL;
  (*p)->s = NULL;
  (*p)->type1 = type1;
  (*p)->type2 = type2;
}

void clear_pair(pair* p) {
  if(p->f != NULL) free(p->f);
  if(p->s != NULL) free(p->s);

  free(p);
}

void set_first(pair* p, void* e) {
  if(p->type1 == 'I') {
    p->f = malloc(sizeof(int64_t));
    int64_t* aux = p->f;
    *aux = *((int64_t*) e);
    return;
  }

  if(p->type1 == 'c') {
    p->f = malloc(sizeof(char));
    char* aux = p->f;
    *aux = *((char*) e);
    return;
  }
}

void set_second(pair* p, void* e) {
  if(p->type2 == 'I') {
    p->s = malloc(sizeof(int64_t));
    int64_t* aux = p->s;
    *aux = *((int64_t*) e);
    return;
  }

  if(p->type2 == 'c') {
    p->s = malloc(sizeof(char));
    char* aux = p->s;
    *aux = *((char*) e);
    return;
  }
}

void* get_first(pair* p) { return p->f; }
void* get_second(pair* p) { return p->s; }

void show_pair(pair* p) {
  printf("{");

  if(p->type1 == 'I') printf("%" PRId64 ", ", *((int64_t*) p->f));
  else if(p->type1 == 'c') printf("%c, ", *(((char*) p->f)));

  if(p->type2 == 'I') printf("%" PRId64, *((int64_t*) p->s));
  else if(p->type2 == 'c') printf("%c", *(((char*) p->s)));

  printf("}");
}

#endif /* ifndef __PAIR__ */
