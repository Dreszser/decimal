#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result) {
    s21_big_decimal rest;
    null_big_decimal(&rest);
    s21_big_decimal big = convert_from_decimal(value);
    while (get_big_exp(big) > 0) {
      rest = divide_by_ten(&big);
      set_big_exp(&big, get_big_exp(big) - 1);
    }
    if (rest.bits[0] >= 5) {
      s21_big_decimal one;
      null_big_decimal(&one);
      one.bits[0] = 1;
      s21_big_bit_add(big, one, &big);
    }
    convert_to_decimal(big, result);
  } else {
    error = 1;
  }
  return error;
}