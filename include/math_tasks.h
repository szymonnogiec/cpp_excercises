#pragma once

#include <cstdint>

namespace math {

static uint64_t sum_of_divisible_by_three_and_five(uint32_t limit) {
  uint64_t result{0};
  for (uint32_t i = 3; i < limit; ++i) {
    if ((i%3)==0 || (i%5)==0) {
      result += i;
    }
  }
  return result;
}

static uint64_t greatest_common_divisor(uint64_t first, uint64_t second) {
  return second == 0 ? first : greatest_common_divisor(second, first % second);
}

};