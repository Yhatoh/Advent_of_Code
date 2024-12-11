// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

uint64_t pos_vector(uint64_t c, uint64_t i, uint64_t j) {
  return i * c + j;
}

int64_t valid(int64_t r, int64_t c, int64_t x, int64_t y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int64_t wall(int64_t c, int64_t x, int64_t y, vector* v) {
  if(*((char*) get(v, pos_vector(c, x, y))) == '#') return 1;
  return 0;
}

int main() {
  vector *grid;
  init_vector(&grid, 'c');
  vector *vis;
  init_vector(&vis, 'I');

  char c;
  uint64_t rows, cols;
  rows = cols = 0;

  while(scanf("%c", &c) != EOF) {
    if(c != '\n') {
      int64_t zero = 0;
      push_back(vis, &zero);

      push_back(grid, &c);
    } else {
      rows++;
    }
  }

  cols = size(grid) / rows;

  int64_t x, y;
  char dir;

  x = y = 0;
  dir = 'u';

  for(uint64_t i = 0; i < rows; i++) {
    for(uint64_t j = 0; j < cols; j++) {
      uint64_t pos = pos_vector(cols, i, j);
      char guard = *((char*) get(grid, pos));
      if(guard == '^') {
        x = i;
        y = j;
        dir = 'u';
      }
    }
  }

  while(valid(rows, cols, x, y)) {
    int64_t one = 1;
    set(vis, pos_vector(cols, x, y), &one);

    if(dir == 'u') {
      if(valid(rows, cols, x - 1, y) && wall(cols, x - 1, y, grid)) {
        dir = 'r';
      } else {
        x--;
      }
    } else if(dir == 'd') {
      if(valid(rows, cols, x + 1, y) && wall(cols, x + 1, y, grid)) {
        dir = 'l';
      } else {
        x++;
      }
    } else if(dir == 'l') {
      if(valid(rows, cols, x, y - 1) && wall(cols, x, y - 1, grid)) {
        dir = 'u';
      } else {
        y--;
      }
    } else {
      if(valid(rows, cols, x, y + 1) && wall(cols, x, y + 1, grid)) {
        dir = 'd';
      } else {
        y++;
      }
    }
  }


  int64_t points = 0;
  for(uint64_t i = 0; i < rows; i++) {
    for(uint64_t j = 0; j < cols; j++) {
      uint64_t pos = pos_vector(cols, i, j);
      int64_t val = *((int64_t*) get(vis, pos));
      if(val) {
        points++;
      }
    }
  }

  printf("%" PRId64 "\n", points);

  clear_vector(grid);
  clear_vector(vis);

  return 0;
}
