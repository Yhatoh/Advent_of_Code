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
  char w = *((char*) get(v, pos_vector(c, x, y)));
  if( w == '#' || w == 'O') return 1;
  return 0;
}

void visit(vector* vis, uint64_t cols, int64_t x, int64_t y, char dir) {
  int64_t one = *((int64_t*) get(vis, pos_vector(cols, x, y)));
  if(dir == 'u') one |= 1;
  else if(dir == 'l') one |= (1 << 1);
  else if(dir == 'd') one |= (1 << 2);
  else one |= (1 << 3);
  set(vis, pos_vector(cols, x, y), &one);
}

int64_t multiworld(vector* grid, uint64_t rows, uint64_t cols, 
                                int64_t x, int64_t y, char dir) {
  vector *vis;
  init_vector(&vis, 'I');
  for(uint64_t i = 0; i < rows; i++) {
    for(uint64_t j = 0; j < cols; j++) {
      int64_t zero = 0;
      push_back(vis, &zero);
    }
  }

  int8_t flag = 0;
//
//  for(uint64_t i = 0; i < rows; i++) {
//    for(uint64_t j = 0; j < cols; j++) {
//      printf("%c", *((char*) get(grid, pos_vector(cols, i, j))));
//    }
//    printf("\n");
//  }
//  printf("\n");
  while(valid(rows, cols, x, y)) {

    int64_t dir_vis = (*((int64_t*) get(vis, pos_vector(cols, x, y))));
    if((dir == 'u' && (dir_vis & (1)) != 0) ||
       (dir == 'l' && (dir_vis & (1 << 1)) != 0) ||
       (dir == 'd' && (dir_vis & (1 << 2)) != 0) ||
       (dir == 'r' && (dir_vis & (1 << 3)) != 0)) {
      flag = 1;
      if(flag) break;
    }

    visit(vis, cols, x, y, dir);

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

  clear_vector(vis);

  return flag;
}

void set_other(vector* v, uint64_t pos, char c) { set(v, pos, &c); }

int main() {
  vector *grid;
  init_vector(&grid, 'c');
  vector *vis;
  init_vector(&vis, 'I');
  vector *rock;
  init_vector(&rock, 'I');

  char c;
  uint64_t rows, cols;
  rows = cols = 0;

  while(scanf("%c", &c) != EOF) {
    if(c != '\n') {
      int64_t zero = 0;
      push_back(vis, &zero);
      push_back(rock, &zero);

      push_back(grid, &c);
    } else {
      rows++;
    }
  }
  cols = size(grid) / rows;

  int64_t x, y;
  int64_t sx, sy;
  char dir, sdir;

  x = y = 0;
  sx = sy = 0;
  dir = 'u';

  for(uint64_t i = 0; i < rows; i++) {
    for(uint64_t j = 0; j < cols; j++) {
      uint64_t pos = pos_vector(cols, i, j);
      char guard = *((char*) get(grid, pos));
      if(guard == '^') {
        x = i;
        y = j;
        dir = 'u';
      } else if(guard == '<') {
        x = i; y = j;
        dir = 'l';
      } else if(guard == '>') {
        x = i; y = j;
        dir = 'r';
      }
    }
  }

  sx = x; sy = y; sdir = dir;

  int64_t points = 0;

  while(valid(rows, cols, x, y)) {
    int64_t dir_vis = *((int64_t*) get(vis, pos_vector(cols, x, y)));
    visit(vis, cols, x, y, dir);
    if(dir == 'u') {
      if(valid(rows, cols, x - 1, y) && wall(cols, x - 1, y, grid)) {
        dir = 'r';
      } else {
        if(valid(rows, cols, x - 1, y) &&
           *((int64_t*) get(rock, pos_vector(cols, x - 1, y))) == 0) {
          set_other(grid, pos_vector(cols, x - 1, y), 'O');
          points += multiworld(grid, rows, cols, sx, sy, sdir);
          set_other(grid, pos_vector(cols, x - 1, y), '.');
          uint64_t one = 1;
          set(rock, pos_vector(cols, x - 1, y), &one);
        }
        x--;
      }
    } else if(dir == 'd') {
      if(valid(rows, cols, x + 1, y) && wall(cols, x + 1, y, grid)) {
        dir = 'l';
      } else {
        if(valid(rows, cols, x + 1, y) &&
           *((int64_t*) get(rock, pos_vector(cols, x + 1, y))) == 0) {
          set_other(grid, pos_vector(cols, x + 1, y), 'O');
          points += multiworld(grid, rows, cols, sx, sy, sdir);
          set_other(grid, pos_vector(cols, x + 1, y), '.');
          uint64_t one = 1;
          set(rock, pos_vector(cols, x + 1, y), &one);
        }
        x++;
      }
    } else if(dir == 'l') {
      if(valid(rows, cols, x, y - 1) && wall(cols, x, y - 1, grid)) {
        dir = 'u';
      } else {
        if(valid(rows, cols, x, y - 1) &&
           *((int64_t*) get(rock, pos_vector(cols, x, y - 1))) == 0) {
          set_other(grid, pos_vector(cols, x, y - 1), 'O');
          points += multiworld(grid, rows, cols, sx, sy, sdir);
          set_other(grid, pos_vector(cols, x, y - 1), '.');
          uint64_t one = 1;
          set(rock, pos_vector(cols, x, y - 1), &one);
        }
        y--;
      }
    } else {
      if(valid(rows, cols, x, y + 1) && wall(cols, x, y + 1, grid)) {
        dir = 'd';
      } else {
        if(valid(rows, cols, x, y + 1) &&
           *((int64_t*) get(rock, pos_vector(cols, x, y + 1))) == 0) {
          set_other(grid, pos_vector(cols, x, y + 1), 'O');
          points += multiworld(grid, rows, cols, sx, sy, sdir);
          set_other(grid, pos_vector(cols, x, y + 1), '.');

          uint64_t one = 1;
          set(rock, pos_vector(cols, x, y + 1), &one);
        }
        y++;
      }
    }
  }



  printf("%" PRId64 "\n", points);

  clear_vector(grid);
  clear_vector(vis);
  clear_vector(rock);

  return 0;
}
