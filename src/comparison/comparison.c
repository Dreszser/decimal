#include "s21_decimal.h"

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  s21_big_decimal temp1 = convert_from_decimal(num1);
  s21_big_decimal temp2 = convert_from_decimal(num2);
  return (big_compare(temp1, temp2) == -1);
}

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  s21_big_decimal temp1 = convert_from_decimal(num1);
  s21_big_decimal temp2 = convert_from_decimal(num2);
  return (big_compare(temp1, temp2) <= 0);
}

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  s21_big_decimal temp1 = convert_from_decimal(num1);
  s21_big_decimal temp2 = convert_from_decimal(num2);
  return (big_compare(temp1, temp2) == 1);
}

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  s21_big_decimal temp1 = convert_from_decimal(num1);
  s21_big_decimal temp2 = convert_from_decimal(num2);
  return (big_compare(temp1, temp2) >= 0);
}

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  s21_big_decimal temp1 = convert_from_decimal(num1);
  s21_big_decimal temp2 = convert_from_decimal(num2);
  return (big_compare(temp1, temp2) == 0);
}

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  s21_big_decimal temp1 = convert_from_decimal(num1);
  s21_big_decimal temp2 = convert_from_decimal(num2);
  return (big_compare(temp1, temp2) != 0);
}