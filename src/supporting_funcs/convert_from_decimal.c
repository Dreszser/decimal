#include "s21_decimal.h"

s21_big_decimal convert_from_decimal(s21_decimal num) {
  s21_big_decimal res;
  null_big_decimal(&res);
  for (int i = 0; i < 4; ++i) {
    if (i == 3) {
      res.bits[i + 4] = num.bits[i];
    } else {
      res.bits[i] = num.bits[i];
    }
  }
  return res;
}