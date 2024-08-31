#include "s21_decimal.h"

int s21_big_bit_mul(s21_big_decimal num1, s21_big_decimal num2,
                    s21_big_decimal *res) {
  int multiplicator;
  s21_big_decimal product;
  null_big_decimal(&product);
  product = num1;
  for (int i = 0; i < 7 * 32; i++) {
    multiplicator = get_big_bit(num2, i);
    if (multiplicator) {
      s21_big_bit_add(*res, product, res);
    }
    shift_left(&product, 1);
  }
  set_big_exp(res, get_big_exp(num1));
  return 0;  // exit code
}