// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

int main() {
  vector* files;
  init_vector(&files, 'I');
  vector* space;
  init_vector(&space, 'I');
  vector* memory;
  init_vector(&memory, 'I');
  
  int64_t index = 0;

  char num;
  uint64_t pre_file = 0;
  uint64_t pre_free = 0;
  while(scanf("%c", &num) != EOF) {
    if(num == '\n') break;
    int64_t value = num - '0';

    if(index % 2 == 0) {
      for(int64_t i = 0; i < value; i++) {
        int64_t id = index / 2;
        push_back(memory, &id);
      }
      push_back(files, &value);
      pre_file += value;
    } else {
      for(int64_t i = 0; i < value; i++) {
        int64_t c = -1;
        push_back(memory, &c);
      }
      push_back(space, &value);
      pre_free += value;
    }
    index++;
  }

  int64_t pos = size(memory) - 1;
  while(pos >= 0) {
    int64_t c = *((char*) get(memory, pos));

    while(c == -1 && pos >= 0) c = *((int64_t*) get(memory, --pos));
    if(pos < 0) break;

    int64_t amount_block = 0;
    //printf("POS %" PRId64 "\n", pos);
    while(c == *((int64_t*) get(memory, pos))) {
      pos--;
      amount_block++;
    }

    int64_t amount_free = 0;
    int64_t index = -1;
    int64_t found = 0;
    for(int64_t i = 0; i <= pos; i++) {
      if(*((int64_t*) get(memory, i)) == -1) {
        if(amount_free == 0) index = i;
        amount_free++;
      } else {
        if(amount_free >= amount_block) {
          found = 1;
          break;
        }
        amount_free = 0;
      }
    }

    if(found) {
//      printf("BLOCK %" PRId64 "\n", amount_block);
//      printf("FREE %" PRId64 "\n", amount_free);
//      printf("POS %" PRId64 "\n", pos);
      for(int64_t i = pos + 1; i < pos + 1 + amount_block; i++) {
        int64_t x = -1;
        set(memory, i, &x);
      }
      for(int64_t i = index; i < index + amount_block; i++) {
        set(memory, i, &c);
      }
    }
//    for(int64_t i = 0; i < size(memory); i++)
//      printf("%c", *((int64_t*) get(memory, i)));
//    printf("\n");
  }

  int64_t check_sum = 0;
  for(int64_t i = 0; i < size(memory); i++) {
    int64_t c = *((char*) get(memory, i));
    if(c != -1)
      check_sum += i * (c);
  }

  printf("%" PRId64 "\n", check_sum);

  clear_vector(memory);
  clear_vector(files);
  clear_vector(space);
  
  return 0;
}
