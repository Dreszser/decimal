#include "s21_decimal.h"

void multiply_by_ten(s21_big_decimal *num) {
  s21_big_decimal temp1 = *num;
  s21_big_decimal temp2 = *num;
  shift_left(&temp1, 3);
  shift_left(&temp2, 1);
  s21_big_bit_add(temp1, temp2, num);
}