#include "s21_decimal.h"

void shift_left(s21_big_decimal *num, unsigned shift) {
  unsigned memory = 0;
  for (int i = 0; i < 7; ++i) {
    unsigned temp = num->bits[i];
    num->bits[i] <<= shift;
    num->bits[i] |= memory;
    memory = temp >> (32 - shift);
  }
}
