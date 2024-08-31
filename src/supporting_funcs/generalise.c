#include "./s21_decimal.h"

void generalise(s21_decimal *decimal_num) {
  s21_big_decimal temp = convert_from_decimal(*decimal_num);
  s21_big_decimal buffer = temp;
  s21_big_decimal reminder = divide_by_ten(&buffer);

  while (is_big_zero(&reminder) && get_big_exp(temp) > 0) {
    divide_by_ten(&temp);
    set_big_exp(&temp, get_big_exp(temp) - 1);
    buffer = temp;
    reminder = divide_by_ten(&buffer);
  }
  convert_to_decimal(temp, decimal_num);
}