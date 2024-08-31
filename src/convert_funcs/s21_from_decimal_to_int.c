#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal decimal_num, int *integer_num) {
  int error = 0;

  s21_decimal temp;

  null_decimal(&temp);

  s21_truncate(decimal_num, &temp);

  if (integer_num && temp.bits[1] == 0 && temp.bits[2] == 0 &&
      (temp.bits[0] <= INT_MAX ||
       (temp.bits[0] == (INT_MIN * -1) && get_sign(temp)))) {
    *integer_num = temp.bits[0];
    *integer_num *= (get_sign(temp) ? -1 : 1);

  } else {
    error = 1;
  }

  return error;
}