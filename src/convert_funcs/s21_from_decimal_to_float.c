#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal decimal_num, float *float_num) {
  int error = 0;
  double temp = 0;

  if (float_num == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < 96; i++) {
      if (get_bit(decimal_num, i)) {
        temp += pow(2, i);
      }
    }
    temp /= (float)pow(10, get_exp(decimal_num));

    *float_num = (temp * (get_sign(decimal_num) ? -1.0 : 1.0));
  }
  return error;
}