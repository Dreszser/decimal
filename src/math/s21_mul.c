#include "s21_decimal.h"

// 0 — OK;
// 1 — the number is too large or equal to infinity;
// 2 — the number is too small or equal to negative infinity;
// 3 — division by 0.

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // code
  int code = 0;
  // перенос в биг
  if (result) {
    null_decimal(result);
    s21_big_decimal temp1 = convert_from_decimal(value_1);
    s21_big_decimal temp2 = convert_from_decimal(value_2);
    s21_big_decimal res = {0};
    // мы побитово перемножаем
    s21_big_bit_mul(temp1, temp2, &res);
    // определяем знак результата
    int sign1 = get_big_sign(temp1);
    int sign2 = get_big_sign(temp2);
    int sign3;
    if (sign1 == sign2)
      sign3 = 0;
    else
      sign3 = 1;

    // определяем степень результата
    int exp1 = get_big_exp(temp1);
    int exp2 = get_big_exp(temp2);
    int exp3 = exp1 + exp2;
    // устанавливаем в результат все как надо
    set_big_exp(&res, exp3);
    set_big_sign(&res, sign3);
    // переводим
    code = convert_to_decimal(res, result);
  }
  return code;
}