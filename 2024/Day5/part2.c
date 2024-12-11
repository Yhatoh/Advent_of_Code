
// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/pair.h"
#include "../lib/ordered_tree.h"
#include "../lib/vector.h"

ordered_tree* tree;

int comp_custom(const void* a, const void* b) {
    int64_t arg1 = *(const int64_t*)a;
    int64_t arg2 = *(const int64_t*)b;

    pair* a_b;
    pair* b_a;
    init_pair(&a_b, 'I', 'I'); set_first(a_b, &arg1); set_second(a_b, &arg2);
    init_pair(&b_a, 'I', 'I'); set_first(b_a, &arg2); set_second(b_a, &arg1);

    void* a_b_itr = find(tree, a_b);
    int ret = 0;

    if(a_b_itr != NULL) ret = -1;

    void* b_a_itr = find(tree, b_a);
    if(b_a_itr != NULL) ret = 1;

    clear_pair(a_b); clear_pair(b_a);
 
    return ret;
}

int main() {
  init_tree(&tree, 'p');

  int64_t a, b;
  while(1) {
    char line[7];
    fgets(line, 7, stdin);
    if(line[0] == '\n') break;

    sscanf(line, "%" PRId64 "|%" PRId64, &a, &b);
    pair* p;
    init_pair(&p, 'I', 'I'); set_first(p, &a); set_second(p, &b);
    insert_tree(tree, p);
  }

  //show_tree(tree); printf("\n");

  int64_t sum = 0;
  while(1) {
    int64_t num; char c;
    if(scanf("%" PRId64 "%c", &num, &c) == EOF) break;

    vector* v;
    vector* sorted;
    init_vector(&v, 'I');
    init_vector(&sorted, 'I');
    push_back(v, &num);
    push_back(sorted, &num);
    while(c != '\n') {
      scanf("%" PRId64 "%c", &num, &c);
      push_back(v, &num);
      push_back(sorted, &num);
    }
    
    
    //show_vector(v); printf("\n");

    qsort(sorted->data, sorted->curr_size, sizeof(int64_t), comp_custom);

    //show_vector(sorted); printf("\n");

    int8_t flag = 1;
    for(uint64_t i = 0; i < size(sorted); i++) {
      int64_t ret_v = *((int64_t*) get(v, i));
      int64_t ret_sorted = *((int64_t*) get(sorted, i));
      if(ret_v != ret_sorted) {
        flag = 0;
        break;
      }
    }

    if(!flag) {
      sum += *((int64_t*) get(sorted, size(sorted) / 2));
    }
    clear_vector(v);
    clear_vector(sorted);
  }
  clear_tree(tree);
  printf("%" PRId64 "\n", sum);
  return 0;
}
