#include "s21_decimal.h"

int s21_from_int_to_decimal(int integer_num, s21_decimal *decimal_num) {
  int error = 0;

  if (decimal_num) {
    null_decimal(decimal_num);
    if (integer_num < 0) {
      integer_num = -integer_num;
      set_sign(decimal_num, 1);
    }
    decimal_num->bits[0] = integer_num;
  } else {
    error = 1;
  }

  return error;
}