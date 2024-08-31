#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int exp = get_exp(value);

  if (result) {
    s21_big_decimal temp;
    null_big_decimal(&temp);
    temp = convert_from_decimal(value);
    for (int i = 0; i < exp; i++) divide_by_ten(&temp);
    convert_to_decimal(temp, result);
    set_exp(result, 0);
  } else {
    error = 1;
  }
  return error;
}
