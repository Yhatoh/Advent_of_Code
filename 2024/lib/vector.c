#ifndef __VECTOR__
#define __VECTOR__

// c includes
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// local includes
#include "pair.h"
#include "vector.h"

void init_vector(vector** v, char type) {
  assert(type == 'I' || type == 'c' || type == 'p' || type == 'v');

  *v = (vector*) malloc(sizeof(vector));
  (*v)->type = type;
  (*v)->data = NULL;
  (*v)->curr_size = 0;
  (*v)->max_size = 0;
}

void clear_vector(vector *v) {
  if(v->data != NULL) {
    if(v->type == 'p') {
      for(uint64_t i = 0; i < v->curr_size; i++) {
        clear_pair(*(((pair**) v->data) + i));
      }
    } else if(v->type == 'v') {
      for(uint64_t i = 0; i < v->curr_size; i++) {
        clear_vector(*(((vector**) v->data) + i));
      }
    }
    free(v->data);
  }
  free(v);
}

void push_back(vector* v, void* e) {
  if(v->data == NULL) {
    if(v->type == 'I') {
      v->data = malloc(sizeof(int64_t));
      int64_t* aux = v->data;
      aux[0] = *((int64_t*) e);
    } else if(v->type == 'c') {
      v->data = malloc(sizeof(char));
      char* aux = v->data;
      aux[0] = *((char*) e);
    } else if(v->type == 'p') {
      v->data = malloc(sizeof(pair*));
      pair** aux = v->data;
      aux[0] = ((pair*) e);
    } else if(v->type == 'v') {
      v->data = malloc(sizeof(vector*));
      vector** aux = v->data;
      aux[0] = ((vector*) e);
    }
    v->curr_size = v->max_size = 1;
    return;
  }

  if(v->curr_size == v->max_size) {
    v->max_size *= 2;
    if(v->type == 'I') {
      v->data =  realloc(v->data, sizeof(int64_t) * v->max_size);
    } else if(v->type == 'c') {
      v->data =  realloc(v->data, sizeof(char) * v->max_size);
    } else if(v->type == 'p') {
      v->data =  realloc(v->data, sizeof(pair*) * v->max_size);
    } else if(v->type == 'v') {
      v->data =  realloc(v->data, sizeof(vector*) * v->max_size);
    }
  }

  if(v->type == 'I') {
    int64_t* aux = v->data;
    aux[v->curr_size++] = *((int64_t*) e);
  } else if(v->type == 'c') {
    char* aux = v->data;
    aux[v->curr_size++] = *((char*) e);
  } else if(v->type == 'p') {
    pair** aux = v->data;
    aux[v->curr_size++] = ((pair*) e);
  } else if(v->type == 'v') {
    vector** aux = v->data;
    aux[v->curr_size++] = ((vector*) e);
  }
}

void pop_back(vector *v) {
  assert(v->curr_size > 0);
  v->curr_size--;
}

void* get(vector *v, uint64_t i) {
  if(v->type == 'I') {
    return ((int64_t*) v->data) + i;
  } else if(v->type == 'c') {
    return ((char*) v->data) + i;
  } else if(v->type == 'p') {
    return ((pair**) v->data) + i;
  } else if(v->type == 'v') {
    return ((vector**) v->data) + i;
  }
  return NULL;
}

void set(vector *v, uint64_t i, void* e) {
  assert(i >= 0 && i < v->curr_size);
  if(v->type == 'I') {
    int64_t* aux = v->data;
    aux[i] = *((int64_t*) e);
  } else if(v->type == 'c') {
    char* aux = v->data;
    aux[i] = *((char*) e);
  } else if(v->type == 'p') {
    pair** aux = v->data;
    aux[i] = ((pair*) e);
  } else if(v->type == 'v') {
    vector** aux = v->data;
    aux[i] = ((vector*) e);
  } 
}

uint64_t size(vector *v) { return v->curr_size; }

void insert(vector *v, void* e, uint64_t i) {
  assert(i >= 0 && i <= v->curr_size);
  if(v->data == NULL) {
    if(v->type == 'I') {
      v->data = malloc(sizeof(int64_t));
      int64_t* aux = v->data;
      aux[0] = *((int64_t*) e);
    } else if(v->type == 'c') {
      v->data = malloc(sizeof(char));
      char* aux = v->data;
      aux[0] = *((char*) e);
    } else if(v->type == 'p') {
      v->data = malloc(sizeof(pair*));
      pair** aux = v->data;
      aux[0] = ((pair*) e);
    } else if(v->type == 'v') {
      v->data = malloc(sizeof(vector*));
      vector** aux = v->data;
      aux[0] = ((vector*) e);
    }
    v->curr_size = v->max_size = 1;
    return;
  }

  if(v->curr_size == v->max_size) {
    v->max_size *= 2;
    if(v->type == 'I') {
      v->data = realloc(v->data, sizeof(int64_t) * v->max_size);
    } else if(v->type == 'c') {
      v->data = realloc(v->data, sizeof(char) * v->max_size);
    } else if(v->type == 'p') {
      v->data = realloc(v->data, sizeof(pair*) * v->max_size);
    } else if(v->type == 'p') {
      v->data = realloc(v->data, sizeof(vector*) * v->max_size);
    }
  }

  v->curr_size++;
  if(v->type == 'I') {
    int64_t* aux = (int64_t*) v->data;
    for(uint64_t j = v->curr_size - 1; j > i; j--) {
      aux[j] = aux[j - 1];
    }
    aux[i] = *((int64_t*) e);
  } else if(v->type == 'c') {
    char* aux = (char*) v->data;
    for(uint64_t j = v->curr_size - 1; j > i; j--) {
      aux[j] = aux[j - 1];
    }
    aux[i] = *((char*) e);
  } else if(v->type == 'p') {
    pair** aux = (pair**) v->data;
    for(uint64_t j = v->curr_size - 1; j > i; j--) {
      aux[j] = aux[j - 1];
    }
    aux[i] = ((pair*) e);
  } else if(v->type == 'v') {
    vector** aux = (vector**) v->data;
    for(uint64_t j = v->curr_size - 1; j > i; j--) {
      aux[j] = aux[j - 1];
    }
    aux[i] = ((vector*) e);
  }
}

void erase(vector *v, uint64_t i) {
  assert(i >= 0 && i < v->curr_size);
  assert(v->curr_size != 0);

  v->curr_size--;
  if(v->type == 'I') {
    int64_t* aux = (int64_t*) v->data;
    for(uint64_t j = i; j < v->curr_size; j++) {
      aux[j] = aux[j + 1];
    }
  } else if(v->type == 'c') {
    char* aux = (char*) v->data;
    for(uint64_t j = i; j < v->curr_size; j++) {
      aux[j] = aux[j + 1];
    }
  } else if(v->type == 'p') {
    pair** aux = (pair**) v->data;
    for(uint64_t j = i; j < v->curr_size; j++) {
      aux[j] = aux[j + 1];
    }
  } else if(v->type == 'p') {
    vector** aux = (vector**) v->data;
    for(uint64_t j = i; j < v->curr_size; j++) {
      aux[j] = aux[j + 1];
    }
  }
}

void show_vector(vector *v) {
  printf("[");
  for(uint64_t i = 0; i < v->curr_size - 1; i++) {
    if(v->type == 'I') {
      printf("%" PRId64, ((int64_t*) v->data)[i]);
    } else if(v->type == 'c') {
      printf("%c", *(((char*) v->data) + i));
    } else if(v->type == 'p') {
      show_pair(*(((pair**) v->data) + i));
    } else if(v->type == 'v') {
      show_vector(*(((vector**) v->data) + i));
    }
    printf(", ");
  }
  if(v->type == 'I') {
    printf("%" PRId64, ((int64_t*) v->data)[v->curr_size - 1]);
  } else if(v->type == 'c') {
    printf("%c", *(((char*) v->data) + v->curr_size - 1));
  } else if(v->type == 'p') {
    show_pair(*(((pair**) v->data) + v->curr_size - 1));
  } else if(v->type == 'v') {
    show_vector(*(((vector**) v->data) + v->curr_size - 1));
  }
  printf("]");
}
#endif
