#include "s21_decimal.h"

void float_scale(int *exp, s21_decimal *decimal_num) {
  if ((*exp) < 0) {
    (*exp) = (*exp) - 6;
    set_exp(decimal_num, -(*exp));
  } else if ((*exp) < 7) {
    set_exp(decimal_num, (6 - (*exp)));
    (*exp) = 0;
  } else {
    (*exp) = (*exp) - 6;
    set_exp(decimal_num, 0);
  }
}