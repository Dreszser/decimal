#include "s21_decimal.h"

s21_big_decimal divide_by_ten(s21_big_decimal *result) {
  unsigned long long overflow = 0;
  s21_big_decimal res;
  null_big_decimal(&res);
  for (int i = 6; i >= 0; i--) {
    unsigned long long save = (overflow << 32) | result->bits[i];
    result->bits[i] = (save / 10);
    overflow = save % 10;
  }
  res.bits[0] = overflow;
  return res;
}