// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

uint64_t pos_vector(uint64_t c, uint64_t i, uint64_t j) {
  return i * c + j;
}

void get_letters(vector *grid, uint64_t pos1, uint64_t pos2, uint64_t pos3, char *M, char *A, char *S) {
  *M = *((char*) get(grid, pos1));
  *A = *((char*) get(grid, pos2));
  *S = *((char*) get(grid, pos3));
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
      char M, A, S;
      if(X == 'X') {
        // horizontal normal check
        if(j < cols - 3) {
          uint64_t pos1 = pos_vector(cols, i, j + 1);
          uint64_t pos2 = pos_vector(cols, i, j + 2);
          uint64_t pos3 = pos_vector(cols, i, j + 3);
          get_letters(grid, pos1, pos2, pos3, &M, &A, &S);
          if(M == 'M' && A == 'A' && S == 'S') {
            count++;
          }
        }
        // horizontal backward check
        if(j >= 3) {
          uint64_t pos1 = pos_vector(cols, i, j - 1);
          uint64_t pos2 = pos_vector(cols, i, j - 2);
          uint64_t pos3 = pos_vector(cols, i, j - 3);
          get_letters(grid, pos1, pos2, pos3, &M, &A, &S);
          if(M == 'M' && A == 'A' && S == 'S') {
            count++;
          }
        }
        // vertical normal check
        if(i < rows - 3) {
          uint64_t pos1 = pos_vector(cols, i + 1, j);
          uint64_t pos2 = pos_vector(cols, i + 2, j);
          uint64_t pos3 = pos_vector(cols, i + 3, j);
          get_letters(grid, pos1, pos2, pos3, &M, &A, &S);
          if(M == 'M' && A == 'A' && S == 'S') {
            count++;
          }
        }
        // vertical backward check
        if(i >= 3) {
          uint64_t pos1 = pos_vector(cols, i - 1, j);
          uint64_t pos2 = pos_vector(cols, i - 2, j);
          uint64_t pos3 = pos_vector(cols, i - 3, j);
          get_letters(grid, pos1, pos2, pos3, &M, &A, &S);
          if(M == 'M' && A == 'A' && S == 'S') {
            count++;
          }
        }
        // diagonal normal check
        if(i < rows - 3 && j < cols - 3) {
          uint64_t pos1 = pos_vector(cols, i + 1, j + 1);
          uint64_t pos2 = pos_vector(cols, i + 2, j + 2);
          uint64_t pos3 = pos_vector(cols, i + 3, j + 3);
          get_letters(grid, pos1, pos2, pos3, &M, &A, &S);
          if(M == 'M' && A == 'A' && S == 'S') {
            count++;
          }
        }
        // diagonal backward check
        if(i >= 3 && j >= 3) {
          uint64_t pos1 = pos_vector(cols, i - 1, j - 1);
          uint64_t pos2 = pos_vector(cols, i - 2, j - 2);
          uint64_t pos3 = pos_vector(cols, i - 3, j - 3);
          get_letters(grid, pos1, pos2, pos3, &M, &A, &S);
          if(M == 'M' && A == 'A' && S == 'S') {
            count++;
          }
        }
        // diagonal normal 2 check
        if(i < rows - 3 && j >= 3) {
          uint64_t pos1 = pos_vector(cols, i + 1, j - 1);
          uint64_t pos2 = pos_vector(cols, i + 2, j - 2);
          uint64_t pos3 = pos_vector(cols, i + 3, j - 3);
          get_letters(grid, pos1, pos2, pos3, &M, &A, &S);
          if(M == 'M' && A == 'A' && S == 'S') {
            count++;
          }
        }
        // diagonal backward 2 check
        if(i >= 3 && j < cols - 3) {
          uint64_t pos1 = pos_vector(cols, i - 1, j + 1);
          uint64_t pos2 = pos_vector(cols, i - 2, j + 2);
          uint64_t pos3 = pos_vector(cols, i - 3, j + 3);
          get_letters(grid, pos1, pos2, pos3, &M, &A, &S);
          if(M == 'M' && A == 'A' && S == 'S') {
            count++;
          }
        }
      }
    }
  }

  printf("%" PRId64 "\n", count);
  clear_vector(grid);
}
