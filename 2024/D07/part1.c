// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

int64_t brute_force(vector* v, uint64_t i, int64_t sum, int64_t obj) {
  if(i == size(v)) return sum == obj;

  int64_t curr_num = *((int64_t*) get(v, i));
  if(brute_force(v, i + 1, sum + curr_num, obj)) return 1;
  if(brute_force(v, i + 1, sum * curr_num, obj)) return 1;
  return 0;
}

int main() {

  int64_t obj;
  int64_t ans = 0;
  while(scanf("%" PRId64 ":", &obj) != EOF) {
    char space;
    scanf("%c", &space);

    vector* nums;
    init_vector(&nums, 'I');

    int64_t num;
    char c;
    while(scanf("%" PRId64 "%c", &num, &c) != EOF) {
      push_back(nums, &num);
      if(c == '\n') break;
    }

    if(brute_force(nums, 1, *((int64_t*) get(nums, 0)), obj)) ans += obj;
  }
  printf("%" PRId64 "\n", ans);
  return 0;
}
