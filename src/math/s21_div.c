#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  if (is_zero(&value_2)) {
    code = 3;
  } else if (is_zero(&value_1)) {
    if (result) null_decimal(result);
  } else if (result) {
    // переводим все в биг
    s21_big_decimal temp1 = convert_from_decimal(value_1);
    s21_big_decimal temp2 = convert_from_decimal(value_2);
    s21_big_decimal res = {0};
    // normalise
    normalise(&temp1, &temp2);
    // мы побитово делим
    s21_big_decimal remainder = s21_big_bit_div(temp1, temp2, &res);
    while (!is_big_zero(&remainder) && get_big_exp(res) < 30) {
      // домножаем остаток на 10 и продолжаем делить пока
      // остаток не станет 0 или скейл не превысит 30
      s21_big_decimal temp_res = {0};
      int scale = get_big_exp(res);
      multiply_by_ten(&remainder);
      multiply_by_ten(&res);
      remainder = s21_big_bit_div(remainder, temp2, &temp_res);

      s21_big_bit_add(res, temp_res, &res);
      set_big_exp(&res, (++scale));
    }
    // определяем знак результата
    int sign = (get_sign(value_1) != get_sign(value_2));
    // устанавливаем в результат все как надо
    set_big_sign(&res, sign);
    // переводим
    code = convert_to_decimal(res, result);
  }
  return code;
}