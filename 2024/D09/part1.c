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
  vector* space2;
  init_vector(&space2, 'I');
  
  int64_t index = 0;

  char num;
  while(scanf("%c", &num) != EOF) {
    if(num == '\n') break;
    int64_t value = num - '0';
    if(index % 2 == 0)
      push_back(files, &value);
    else
      push_back(space, &value), push_back(space2, &value);
    index++;
  }

  int64_t checksum = 0; 

  int64_t r = size(files) - 1;
  int64_t b = 0;

  int64_t pos_space = *((int64_t*) get(files, b));
  while(r > b) {
    int64_t id_ = r;
    int64_t amount_free = *((int64_t*) get(space, b));

    int64_t amount_block = *((int64_t*) get(files, r));
    while(amount_free > 0 && amount_block > 0) {
      checksum += id_ * (pos_space++);
      amount_free--;
      amount_block--;
    }

    if(amount_free == 0 && amount_block == 0) {
      set(space, b, &amount_free);
      b++;
      if(b >= size(space)) break;

      pos_space += *((int64_t*) get(files, b));
      set(files, r, &amount_block);
      r--;
    } else if(amount_free == 0) {
      set(space, b, &amount_free);
      b++;
      if(b >= size(space)) break;
      pos_space += *((int64_t*) get(files, b));
      set(files, r, &amount_block);
    } else {
      set(files, r, &amount_block);
      r--;
      set(space, b, &amount_free);
    }
  }


  int64_t pos2 = 0;
  for(uint64_t i = 0; i < size(files); i++) {
    int64_t amount_block = *((int64_t*) get(files, i));
    while(amount_block--) {
      checksum += i * (pos2++);
    }
    if(i == size(files)) break;
    int64_t amount_free = *((int64_t*) get(space2, i));
    pos2 += amount_free;
  }
  printf("%" PRId64 "\n", checksum);

  clear_vector(files);
  clear_vector(space);
  clear_vector(space2);

  return 0;
}
