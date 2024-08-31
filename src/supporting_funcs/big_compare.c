#include "s21_decimal.h"

int big_compare(s21_big_decimal num1, s21_big_decimal num2) {
  if (get_big_exp(num1) != get_big_exp(num2)) {
    normalise(&num1, &num2);
  }
  int result = 0;
  int sign1 = get_big_sign(num1);
  int sign2 = get_big_sign(num2);
  for (int i = 0; i < 7 && result == 0; ++i) {
    if ((unsigned)num1.bits[6 - i] > (unsigned)num2.bits[6 - i]) {
      result = (!sign1 ? 1 : -1);
    } else if ((unsigned)num1.bits[6 - i] < (unsigned)num2.bits[6 - i]) {
      result = (sign2 ? 1 : -1);
    } else if (!is_big_zero(&num1) && !is_big_zero(&num2)) {
      if (sign1 == 0 && sign2 == 1)
        result = 1;
      else if (sign1 == 1 && sign2 == 0)
        result = -1;
    }
  }
  return result;
}