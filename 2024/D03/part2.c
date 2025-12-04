// c includes
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

// local includes
#include "../lib/vector.h"

int main() {
  vector* code;
  init_vector(&code, 'c');

  char read;
  while(scanf("%c", &read) != EOF) {
    push_back(code, &read);
  }

  uint8_t mul = 0;
  uint8_t open = 0;
  uint8_t close = 0;
  uint8_t dont = 0;

  uint8_t num_1 = 0;
  uint8_t num_2 = 0;
  vector* num1, *num2;
  init_vector(&num1, 'I');
  init_vector(&num2, 'I');


  int64_t add_mul = 0;

  for(uint64_t i = 0; i < size(code); i++) {
    if(mul) {
      char p = *((char*) get(code, i));
      if(open == 0) {
        if(p == '(') {
          open = 1;
        } else {
          i -= 1;
          mul = 0;
        }
      } else if(num_1 == 0) {
        if(size(num1) == 0) {
          if(p >= '1' && p <= '9') {
            int64_t num = p - '0';
            push_back(num1, &num);
          } else {
            i -= 1;
            mul = open = 0;
            clear_vector(num1);
            init_vector(&num1, 'I');
          }
        } else {
          if(p >= '0' && p <= '9') {
            int64_t num = p - '0';
            push_back(num1, &num);
          } else if(p == ',') {
            num_1 = 1;
          } else {
            i -= 1;
            mul = open = 0;
            clear_vector(num1);
            init_vector(&num1, 'I');
          }
        }
      } else if(num_2 == 0) {
        if(size(num2) == 0) {
          if(p >= '1' && p <= '9') {
            int64_t num = p - '0';
            push_back(num2, &num);
          } else {
            i -= 1;
            mul = open = num_1 = 0;
            clear_vector(num1);
            init_vector(&num1, 'I');
            clear_vector(num2);
            init_vector(&num2, 'I');
          }
        } else {
          if(p >= '0' && p <= '9') {
            int64_t num = p - '0';
            push_back(num2, &num);
          } else if(p == ')') {
            int64_t pow10 = 1;
            int64_t res_num1 = 0;
            for(uint64_t j = size(num1) - 1; j >= 0; j--) {
              int64_t digit = *((int64_t*) get(num1, j));
              res_num1 += pow10 * (digit);
              pow10 *= 10;
              if(j == 0) break;
            }
            pow10 = 1;
            int64_t res_num2 = 0;
            for(uint64_t j = size(num2) - 1; j >= 0; j--) {
              int64_t digit = *((int64_t*) get(num2, j));
              res_num2 += pow10 * (digit);
              pow10 *= 10;
              if(j == 0) break;
            }
            add_mul += (res_num1 * res_num2);
            clear_vector(num1);
            init_vector(&num1, 'I');
            clear_vector(num2);
            init_vector(&num2, 'I');
            mul = open = num_1 = 0;
          } else {
            i -= 1;
            mul = open = num_1 = 0;
            clear_vector(num1);
            init_vector(&num1, 'I');
            clear_vector(num2);
            init_vector(&num2, 'I');
          }
        }
      }
    } else if(dont == 0) {
      if(i < size(code) - 3) {
        char c1 = *((char*) get(code, i));
        char c2 = *((char*) get(code, i + 1));
        char c3 = *((char*) get(code, i + 2));
        if(c1 == 'm' && c2 == 'u' && c3 == 'l') {
          i += 2, mul = 1;
          continue;
        }
      }
      if(i < size(code) - 7) {
        char word[] = "don't()";
        uint8_t dont_ = 1;
        for(uint64_t j = 0; j < 7; j++) {
          char c1 = *((char*) get(code, i + j));
          if(c1 != word[j]) dont_ = 0;
        }
        if(dont_) {
          i += 6, dont = 1;
          continue;
        }
      }
    } else { 
      if(i < size(code) - 4) {
        char c1 = *((char*) get(code, i));
        char c2 = *((char*) get(code, i + 1));
        char c3 = *((char*) get(code, i + 2));
        char c4 = *((char*) get(code, i + 3));
        if(c1 == 'd' && c2 == 'o' && c3 == '(' && c4 == ')') {
          dont = 0;
          i += 3;
        }
      }
    }
  }
  printf("%" PRId64 "\n", add_mul);

  clear_vector(code);
  clear_vector(num1);
  clear_vector(num2);
}
