// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"
#include "../lib/pair.h"

uint64_t pos_vector(uint64_t c, uint64_t i, uint64_t j) {
  return i * c + j;
}

int64_t valid(int64_t r, int64_t c, int64_t x, int64_t y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int main() {
  vector *grid;
  init_vector(&grid, 'c');
  vector *antinodes;
  init_vector(&antinodes, 'I');

  char x;
  uint64_t rows, cols;
  rows = cols = 0;
  while(scanf("%c", &x) != EOF) {
    if(x != '\n') {
      push_back(grid, &x);
      int64_t zero = 0;
      push_back(antinodes, &zero);
    } else {
      rows++;
    }
  }

  cols = size(grid) / rows;

  vector *poss;
  init_vector(&poss, 'p');

  for(uint64_t i = 0; i < rows; i++) {
    for(uint64_t j = 0; j < cols; j++) {
      uint64_t pos = pos_vector(cols, i, j);
      char c = *((char*) get(grid, pos));
      if(c != '.') {
        pair* p;
        init_pair(&p, 'I', 'I');
        set_first(p, &i);
        set_second(p, &j);
        push_back(poss, p);
      }
    }
  }

  for(uint64_t i = 0; i < size(poss); i++) {
    pair* act = *((pair**) get(poss, i));
    uint64_t pos_act =
      pos_vector(cols, *((int64_t*) get_first(act)), *((int64_t*) get_second(act)));
    int64_t x_act = *((int64_t*) get_first(act));
    int64_t y_act = *((int64_t*) get_second(act));

    char freq_act = *((char*) get(grid, pos_act));

    for(uint64_t j = 0; j < size(poss); j++) {
      if(i == j) continue;

      pair* cmp = *((pair**) get(poss, j));
      uint64_t pos_cmp = 
        pos_vector(cols, *((int64_t*) get_first(cmp)), *((int64_t*) get_second(cmp)));
      char freq_cmp = *((char*) get(grid, pos_cmp));

      int64_t x_cmp = *((int64_t*) get_first(cmp));
      int64_t y_cmp = *((int64_t*) get_second(cmp));


      if(freq_cmp != freq_act) {
        continue;
      }


      int64_t x_dist = x_act - x_cmp;
      int64_t y_dist = y_act - y_cmp;

      int64_t x_new_1 = x_act + x_dist;
      int64_t y_new_1 = y_act + y_dist;

      int64_t x_new_2 = x_cmp - x_dist;
      int64_t y_new_2 = y_cmp - y_dist;

      if(valid(rows, cols, x_new_1, y_new_1)) {
        char grid_ = *((char*) get(grid, pos_vector(cols, x_new_1, y_new_1)));
        int64_t one = 1;
        set(antinodes, pos_vector(cols, x_new_1, y_new_1), &one);
      }

      if(valid(rows, cols, x_new_2, y_new_2)) {
        char grid_ = *((char*) get(grid, pos_vector(cols, x_new_2, y_new_2)));
        int64_t one = 1;
        set(antinodes, pos_vector(cols, x_new_2, y_new_2), &one);
      }
    }
  }

  int64_t count = 0;
  for(uint64_t i = 0; i < size(grid); i++) {
    if(*((int64_t*) get(antinodes, i)) == 1) count++;
  }
  printf("%" PRId64 "\n", count);
  clear_vector(poss);
  clear_vector(grid);
  clear_vector(antinodes);
  return 0;
}
