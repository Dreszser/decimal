#include "s21_decimal.h"

void normalise(s21_big_decimal *num1, s21_big_decimal *num2) {
  int scale1 = get_big_exp(*num1);
  int scale2 = get_big_exp(*num2);
  if (scale1 > scale2) {
    int delta = scale1 - scale2;
    for (int i = 0; i < delta; ++i) {
      multiply_by_ten(num2);
      ++scale2;
    }
    set_big_exp(num2, scale2);
  } else if (scale1 < scale2) {
    int delta = scale2 - scale1;
    for (int i = 0; i < delta; ++i) {
      multiply_by_ten(num1);
      ++scale1;
    }
    set_big_exp(num1, scale1);
  }
}