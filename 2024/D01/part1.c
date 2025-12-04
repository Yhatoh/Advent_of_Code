// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"
#include "../lib/sort.h"

int main() {
  int64_t left, right;
  vector* left_nums;
  vector* right_nums;
  init_vector(&left_nums, 'I');
  init_vector(&right_nums, 'I');

  while(scanf("%" SCNd64 "   %" SCNd64, &left, &right) != EOF) {
    push_back(left_nums, &left);
    push_back(right_nums, &right);
  }

  sort(left_nums);
  sort(right_nums);

  int64_t ans = 0;
  for(uint64_t i = 0; i < size(left_nums); i++) {
    int64_t left = *((int64_t*) get(left_nums, i));
    int64_t right = *((int64_t*) get(right_nums, i));
    if(left > right) {
      int64_t aux = right;
      right = left;
      left = aux;
    }

    ans += right - left;
  }

  printf("%" PRId64 "\n", ans);

  clear_vector(left_nums);
  clear_vector(right_nums);
  return 0;
}
