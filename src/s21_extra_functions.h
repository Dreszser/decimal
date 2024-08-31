#ifndef S21_EXTRA
#define S21_EXTRA

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned bits[8];
} s21_big_decimal;

/* BIG DECIMAL FUNCTIONS */

void print_big_dec(s21_big_decimal num);
int is_big_zero(s21_big_decimal *num);
void null_big_decimal(s21_big_decimal *num);

int get_big_exp(s21_big_decimal num);
void set_big_exp(s21_big_decimal *num, int exp);

int get_big_sign(s21_big_decimal num);
void set_big_sign(s21_big_decimal *num, int sign);

int set_big_bit(s21_big_decimal *num, int bit_pos, int bit);
int get_big_bit(s21_big_decimal num, int bit_pos);

int big_compare(s21_big_decimal num1, s21_big_decimal num2);

void shift_left(s21_big_decimal *num, unsigned shift);

void normalise(s21_big_decimal *num1, s21_big_decimal *num2);

void multiply_by_ten(s21_big_decimal *num);
s21_big_decimal divide_by_ten(s21_big_decimal *result);

int find_significant_big_bit(s21_big_decimal num);

/* BIG DECIMAL MATH */

int s21_big_bit_add(s21_big_decimal num1, s21_big_decimal num2,
                    s21_big_decimal *res);
int s21_big_bit_sub(s21_big_decimal num1, s21_big_decimal num2,
                    s21_big_decimal *res);
int s21_big_bit_mul(s21_big_decimal num1, s21_big_decimal num2,
                    s21_big_decimal *res);
s21_big_decimal s21_big_bit_div(s21_big_decimal num1, s21_big_decimal num2,
                                s21_big_decimal *res);

/* BANK ROUNDING */

s21_big_decimal big_bank_rounding(s21_big_decimal remainder,
                                  s21_big_decimal num, int flag);

int big_abs_compare(s21_big_decimal num1, s21_big_decimal num2);

#endif  // S21_EXTRA
