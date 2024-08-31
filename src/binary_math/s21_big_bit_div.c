#include "s21_decimal.h"

int find_significant_big_bit(s21_big_decimal num) {
  int result = -1;
  for (int i = 32 * 7 - 1; i >= 0; i--) {
    if (get_big_bit(num, i)) {
      result = i;
      break;
    }
  }
  return result;
}

s21_big_decimal s21_big_bit_div(s21_big_decimal num1, s21_big_decimal num2,
                                s21_big_decimal *res) {
  set_big_exp(&num1, 0);
  set_big_exp(&num2, 0);
  set_big_sign(&num1, 0);
  set_big_sign(&num2, 0);
  s21_big_decimal remainder = num1;
  s21_big_decimal temp2 = num2;
  int diff =
      find_significant_big_bit(remainder) - find_significant_big_bit(num2);

  while (diff >= 0) {
    temp2 = num2;
    int temp_diff = diff;
    while (temp_diff > 0) {
      shift_left(&temp2, 1);
      --temp_diff;
    }
    shift_left(res, 1);
    if (big_compare(remainder, temp2) >= 0) {
      s21_big_bit_sub(remainder, temp2, &remainder);
      set_big_bit(res, 0, 1);
    }
    diff--;
  }
  set_big_exp(res, get_big_exp(num1));
  return remainder;
}