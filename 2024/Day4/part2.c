// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

uint64_t pos_vector(uint64_t c, uint64_t i, uint64_t j) {
  return i * c + j;
}

void get_letters(vector *grid,
                 uint64_t pos1, uint64_t pos2, uint64_t pos3, uint64_t pos4,
                 char *M, char *A, char *S, char *X2) {
  *M = *((char*) get(grid, pos1));
  *A = *((char*) get(grid, pos2));
  *S = *((char*) get(grid, pos3));
  *X2 = *((char*) get(grid, pos4));
}

int main() {
  vector *grid;
  init_vector(&grid, 'c');

  char x;
  uint64_t rows, cols;
  rows = cols = 0;
  while(scanf("%c", &x) != EOF) {
    if(x != '\n') {
      push_back(grid, &x);
    } else {
      rows++;
    }
  }

  cols = size(grid) / rows;

  int64_t count = 0;
  for(uint64_t i = 0; i < rows; i++) {
    for(uint64_t j = 0; j < cols; j++) {
      uint64_t pos = pos_vector(cols, i, j);
      char X = *((char*) get(grid, pos));
      char M, A, S, X2;
      if(X == 'A') {
        if(i >= 1 && i < rows - 1 && j >= 1 && j < cols - 1) {
          uint64_t pos1 = pos_vector(cols, i - 1, j - 1);
          uint64_t pos2 = pos_vector(cols, i - 1, j + 1);
          uint64_t pos3 = pos_vector(cols, i + 1, j - 1);
          uint64_t pos4 = pos_vector(cols, i + 1, j + 1);
          get_letters(grid, pos1, pos2, pos3, pos4, &M, &A, &S, &X2);

          if(M == 'M' && A == 'M' && S == 'S' && X2 == 'S') count++;
          if(M == 'M' && A == 'S' && S == 'M' && X2 == 'S') count++;
          if(M == 'S' && A == 'M' && S == 'S' && X2 == 'M') count++;
          if(M == 'S' && A == 'S' && S == 'M' && X2 == 'M') count++;
        }
      }
    }
  }

  printf("%" PRId64 "\n", count);
  clear_vector(grid);
}
