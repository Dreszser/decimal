#include "s21_decimal.h"

int is_zero(s21_decimal *num) {
  return ((num->bits[0] == 0) && (num->bits[1] == 0) && (num->bits[2] == 0));
}

void null_decimal(s21_decimal *num) {
  for (int i = 0; i < 4; ++i) {
    num->bits[i] = 0;
  }
}

void print_dec(s21_decimal num) {
  printf("{{0x%x, 0x%x, 0x%x, 0x%x}};\n", num.bits[0], num.bits[1], num.bits[2],
         num.bits[3]);
}

void print_big_dec(s21_big_decimal num) {
  printf("{{0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x}};\n", num.bits[0],
         num.bits[1], num.bits[2], num.bits[3], num.bits[4], num.bits[5],
         num.bits[6], num.bits[7]);
}

int is_big_zero(s21_big_decimal *num) {
  return ((num->bits[0] == 0) && (num->bits[2] == 0) && (num->bits[3] == 0) &&
          (num->bits[4] == 0) && (num->bits[5] == 0) && (num->bits[6] == 0));
}

void null_big_decimal(s21_big_decimal *num) {
  for (int i = 0; i < 8; ++i) {
    num->bits[i] = 0;
  }
}