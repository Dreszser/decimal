#include "s21_decimal.h"

int s21_from_float_to_decimal(float float_num, s21_decimal *decimal_num) {
  int error = 0, exp = 0, sign = 0, fractional_part = 0;
  char string[15] = {0};
  unsigned integer = 0;
  double num = 0;

  if ((decimal_num == NULL) || (isinf(float_num)) || (isnan(float_num)))
    error = 1;
  else if ((0 < fabs(float_num)) && (fabs(float_num) < FLOAT_MIN)) {
    error = 1;
    null_decimal(decimal_num);
  } else if (fabs(float_num) > FLOAT_MAX) {
    error = 1;
    null_decimal(decimal_num);
  } else if (float_num == 0)
    null_decimal(decimal_num);
  else {
    null_decimal(decimal_num);
    sprintf(string, "%E", float_num);
    num = atof(strtok(string, "E"));
    if (num < 0) {  // Добавил учёт знака
      sign = 1;
      num = fabs(num);
    }
    exp = (atoi(strtok(NULL, "E")));
    float_scale(&exp, decimal_num);
    for (int i = 2; string[i] != '\0'; i++)
      if (string[i] != '.') fractional_part++;
    integer = (num * pow(10, fractional_part));
    while (get_exp(*decimal_num) >
           28) {  // Отбрасываем цифры пока мантисса не станет 28
      integer /= 10;
      set_exp(decimal_num, get_exp(*decimal_num) - 1);
    }

    set_sign(decimal_num, sign);
    decimal_num->bits[0] = integer;
    while (exp > 0) {
      s21_decimal ten = {{0xa, 0x0, 0x0, 0x0}};
      s21_mul(*decimal_num, ten, decimal_num);
      --exp;
    }
    generalise(decimal_num);
  }
  return error;
}