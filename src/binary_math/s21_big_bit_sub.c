#include "s21_decimal.h"

int s21_big_bit_sub(s21_big_decimal num1, s21_big_decimal num2,
                    s21_big_decimal *res) {
  unsigned int overflow = 0;
  for (int i = 0; i < 7 * 32; i++) {
    int sum = 0;
    sum = get_big_bit(num1, i) - get_big_bit(num2, i) - overflow;
    switch (sum) {
      case 0:
        overflow = 0;
        break;
      case -1:
        sum = 1;
        overflow = 1;
        break;
      case -2:
        sum = 0;
        overflow = 1;
        break;
      default:
        break;
    }
    set_big_bit(res, i, sum);
  }
  set_big_exp(res, get_big_exp(num1));
  return 0;  // exit code
}
