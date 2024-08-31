#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result) {
    *result = value;
    set_sign(result, !get_sign(*result));
  } else {
    error = 1;
  }
  return error;
}