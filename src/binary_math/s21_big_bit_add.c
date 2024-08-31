#include "s21_decimal.h"

int s21_big_bit_add(s21_big_decimal num1, s21_big_decimal num2,
                    s21_big_decimal *res) {
  unsigned int overflow = 0;
  for (int i = 0; i < 7 * 32; i++) {
    int sum = 0;
    sum = get_big_bit(num1, i) + get_big_bit(num2, i) + overflow;
    overflow = sum / 2;
    set_big_bit(res, i, sum % 2);
  }
  set_big_exp(res, get_big_exp(num1));
  return 0;
}