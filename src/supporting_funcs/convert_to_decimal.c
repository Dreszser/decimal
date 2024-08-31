#include "s21_decimal.h"

/*
    0 — OK;
    1 — the number is too large or equal to infinity;
    2 — the number is too small or equal to negative infinity;
*/

int convert_to_decimal(s21_big_decimal num, s21_decimal *res) {
  null_decimal(res);
  s21_big_decimal remainder = {0};
  null_big_decimal(&remainder);
  int exit_code = 0;
  int flag = 0;
  int scale = get_big_exp(num);
  int pos = find_significant_big_bit(num);
  while ((pos > (32 * 3) - 1 && scale > 0) || scale > 28) {
    remainder = divide_by_ten(&num);
    --scale;
    pos = find_significant_big_bit(num);
    if ((pos > (32 * 3) - 1 && scale > 0) || scale > 28) {
      if (!is_big_zero(&remainder)) flag = 1;
    }
  }
  num = big_bank_rounding(remainder, num, flag);
  if (find_significant_big_bit(num) > (32 * 3) - 1) {
    if (get_big_sign(num))
      exit_code = 2;
    else
      exit_code = 1;
  } else {
    for (int i = 0; i < 3; ++i) {
      res->bits[i] = num.bits[i];
    }
    set_exp(res, scale);
    set_sign(res, get_big_sign(num));
  }
  return exit_code;
}

s21_big_decimal big_bank_rounding(s21_big_decimal remainder,
                                  s21_big_decimal num, int flag) {
  s21_big_decimal five;
  null_big_decimal(&five);
  five.bits[0] = 5;
  s21_big_decimal one;
  null_big_decimal(&one);
  one.bits[0] = 1;
  switch (big_compare(remainder, five)) {
    case 1:
      s21_big_bit_add(num, one, &num);
      break;
    case 0: {
      if (flag)
        s21_big_bit_add(num, one, &num);
      else if (get_big_bit(num, 0))
        s21_big_bit_add(num, one, &num);
    } break;
  }
  return num;
}
