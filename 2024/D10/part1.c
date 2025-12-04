// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

int64_t rows = 0;
int64_t cols = 0;

uint64_t pos_vector(uint64_t c, uint64_t i, uint64_t j) {
  return i * c + j;
}

int64_t valid(int64_t x, int64_t y) {
  return x >= 0 && x < rows && y >= 0 && y < cols;
}

int64_t dfs(vector *map, vector *vis, int x, int y) {
  int64_t one = 1;
  set(vis, pos_vector(cols, x, y), &one);
  int64_t h = *((int64_t*) get(map, pos_vector(cols, x, y)));
  if(h == 9) return 1;
  
  int64_t ret = 0;
  if(valid(x - 1, y) && h + 1 == *((int64_t*) get(map, pos_vector(cols, x - 1, y)))) {
    if(*((int64_t*) get(vis, pos_vector(cols, x - 1, y))) == 0)
      ret += dfs(map, vis, x - 1, y);
  }
  
  if(valid(x + 1, y) && h + 1 == *((int64_t*) get(map, pos_vector(cols, x + 1, y)))) {
    if(*((int64_t*) get(vis, pos_vector(cols, x + 1, y))) == 0)
      ret += dfs(map, vis, x + 1, y);
  }
  
  if(valid(x, y - 1) && h + 1 == *((int64_t*) get(map, pos_vector(cols, x, y - 1)))) {
    if(*((int64_t*) get(vis, pos_vector(cols, x, y - 1))) == 0)
      ret += dfs(map, vis, x, y - 1);
  }
  
  if(valid(x, y + 1) && h + 1 == *((int64_t*) get(map, pos_vector(cols, x, y + 1)))) {
    if(*((int64_t*) get(vis, pos_vector(cols, x, y + 1))) == 0)
      ret += dfs(map, vis, x, y + 1);
  }
  return ret;
}
int main() {
  vector* map;
  init_vector(&map, 'I');
  
  int64_t index = 0;

  char num;
  while(scanf("%c", &num) != EOF) {
    if(num == '\n') {
      rows++;
      continue;
    }
    int64_t value = num - '0';

    push_back(map, &value);
  }

  cols = size(map) / rows;

  int64_t score = 0;
  for(int64_t i = 0; i < rows; i++) {
    for(uint64_t j = 0; j <  cols; j++) {
      int64_t h = *((int64_t*) get(map, pos_vector(cols, i, j)));
      if(h == 0) {
        vector* vis;
        init_vector(&vis, 'I');
        for(int64_t i = 0; i < size(map); i++) {
          int64_t zero = 0;
          push_back(vis, &zero);
        }

        int64_t local = dfs(map, vis, i, j);
        score += local;
        clear_vector(vis);
      }
    }
  }
  printf("%" PRId64 "\n", score);
  clear_vector(map);
  return 0;
}
