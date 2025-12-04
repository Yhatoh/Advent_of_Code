// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

int main() {
  vector* report;
  init_vector(&report, 'I');

  int64_t level;
  char space;

  uint64_t safe = 0;
  while(scanf("%" SCNd64 "%c", &level, &space) != EOF) {
    push_back(report, &level);
    if(space == '\n') {
      //show(report);
      if(size(report) == 1) {
        safe++;
      } else {
        uint8_t incre = 1;
        uint8_t decre = 1;
        uint8_t differ = 1;
        for(uint64_t i = 0; i < size(report) - 1; i++) {
          uint64_t pos_i = *((int64_t*) get(report, i));
          uint64_t pos_i_1 = *((int64_t*) get(report, i + 1));
          if(pos_i == pos_i_1) incre = decre = 0;
          if(pos_i > pos_i_1) {
            incre = 0;
            if(!(pos_i - pos_i_1 >= 1 && pos_i - pos_i_1 <= 3)) differ = 0;
          }
          if(pos_i < pos_i_1) {
            decre = 0;
            if(!(pos_i_1 - pos_i >= 1 && pos_i_1 - pos_i <= 3)) differ = 0;
          }
        }
        if((incre || decre) && differ) {
          safe++;
        }
      }
      clear_vector(report);
      init_vector(&report, 'I');
    }
  } 
  clear_vector(report);

  printf("%" PRId64 "\n", safe);
}
