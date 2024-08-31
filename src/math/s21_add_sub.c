#include "s21_decimal.h"

int big_abs_compare(s21_big_decimal num1, s21_big_decimal num2) {
  // if (get_big_exp(num1) != get_big_exp(num2)) {
  //   normalise(&num1, &num2);
  // }
  int result = 0;
  for (int i = 0; i < 7 && result == 0; ++i) {
    if ((unsigned)num1.bits[6 - i] > (unsigned)num2.bits[6 - i]) {
      result = 1;
    } else if ((unsigned)num1.bits[6 - i] < (unsigned)num2.bits[6 - i]) {
      result = -1;
    }
  }
  return result;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  if (result) {
    null_decimal(result);
    // итак, сюда приходит 2 операнда в виде децимала и указатель на децимал
    //(результат) мы переводим все в биг децимал
    s21_big_decimal temp1 = convert_from_decimal(value_1);
    s21_big_decimal temp2 = convert_from_decimal(value_2);
    s21_big_decimal res = {0};
    // нормализуем
    normalise(&temp1, &temp2);
    // смотрим на знак и приходим к заключению, что из чего вычитать, и какой
    // знак и экспонента будут у результата
    int sign1 = get_big_sign(temp1);
    int sign2 = get_big_sign(temp2);
    int compare = big_abs_compare(temp1, temp2);
    // знак одинаковый тогда служебный инт у результата такой же и просто
    // складываем
    if (sign1 == sign2) {
      res.bits[7] = temp1.bits[7];
      s21_big_bit_add(temp1, temp2, &res);
    } else {
      // если большее число отрицательно
      //  1 БОЛЬШЕ
      if (compare == 1 && sign1 == 1) {
        res.bits[7] = temp1.bits[7];
        s21_big_bit_sub(temp1, temp2, &res);
      }
      if (compare == -1 && sign2 == 1) {
        res.bits[7] = temp2.bits[7];
        s21_big_bit_sub(temp2, temp1, &res);
      }
      // если меньшее число отрицательно
      //  2 больше
      if (compare == -1 && sign1 == 1) {
        res.bits[7] = temp2.bits[7];
        s21_big_bit_sub(temp2, temp1, &res);
      }
      // 1 больше
      if (compare == 1 && sign2 == 1) {
        res.bits[7] = temp1.bits[7];
        s21_big_bit_sub(temp1, temp2, &res);
      }
      // если числа равны
      if (compare == 0) {
        res.bits[7] = temp1.bits[7];
        s21_big_bit_sub(temp1, temp2, &res);
      }
    }
    // теперь нужно перевести из биг децимала в децимал результат
    code = convert_to_decimal(res, result);
  }
  return code;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  set_sign(&value_2, !get_sign(value_2));
  int code = s21_add(value_1, value_2, result);
  return code;
}