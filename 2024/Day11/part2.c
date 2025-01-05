// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

int64_t vector_to_num(vector* v) {
  int64_t pow10 = 1;
  int64_t ret = 0;
  for(int64_t i = size(v) - 1; i >= 0; i--) {
    ret += pow10 * *((int64_t*) get(v, i));
    pow10 *= 10;
  }
  return ret;
}

int main() {
  vector* stones;
  init_vector(&stones, 'v');

  char num[100];
  char space;
  while(scanf("%s%c", num, &space) != EOF) {
    vector* vec_num;
    init_vector(&vec_num, 'I');
    for(uint64_t i = 0; num[i] != '\0'; i++) {
      int64_t value = num[i] - '0';
      push_back(vec_num, &value);
    }
    push_back(stones, vec_num);
  }

  //show_vector(stones); printf("\n");

  for(uint64_t blink = 0; blink < 25; blink++) {
    vector* new_stones;
    init_vector(&new_stones, 'v');
    for(uint64_t i = 0; i < size(stones); i++) {
      vector* stone = *((vector**) get(stones, i));
      vector* new_stone; init_vector(&new_stone, 'I');
      
      if(size(stone) == 1 && *((int64_t*) get(stone, 0)) == 0) {
        uint64_t one = 1;
        push_back(new_stone, &one);
      } else if(size(stone) % 2 == 0) {
        vector* new_stone1; init_vector(&new_stone1, 'I');
        for(uint64_t i = 0; i < size(stone) / 2; i++) {
          push_back(new_stone1, (int64_t*) get(stone, i));
        }
        push_back(new_stones, new_stone1);
        int8_t found = 0;
        for(uint64_t i = size(stone) / 2; i < size(stone); i++) {
          if(*((int64_t*) get(stone, i)) != 0) found = 1;
          if(found) push_back(new_stone, (int64_t*) get(stone, i));
        }
        if(!found) {
          int64_t zero = 0;
          push_back(new_stone, &zero);
        }
      } else {
        int64_t value = vector_to_num(stone);
        value *= 2024;
        char num[100];
        sprintf(num, "%" PRId64, value);
        for(uint64_t i = 0; num[i] != '\0'; i++) {
          int64_t value = num[i] - '0';
          push_back(new_stone, &value);
        }
      }
      push_back(new_stones, new_stone);
    }
    clear_vector(stones);
    stones = new_stones;
  }

//  for(uint64_t i = 0; i < size(stones); i++) {
//    int64_t value = vector_to_num(*((vector**) get(stones, i)));
//    printf("%" PRId64 " ", value);
//  }
//  printf("\n");

  printf("%" PRId64 "\n", size(stones));
  clear_vector(stones);
  return 0;
}
