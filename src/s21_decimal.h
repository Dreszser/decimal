#ifndef S21_DECIMAL
#define S21_DECIMAL

#include "s21_extra_functions.h"

#define EXP_MASK 0xFF0000     // 00000000 11111111 00000000 00000000
#define SIGN_MASK 0x80000000  // 10000000 00000000 00000000 00000000

#define INT_MIN -2147483648
#define INT_MAX 2147483647

#define FLOAT_MIN 1e-28
#define FLOAT_MAX 79228162514264337593543950335.f

typedef struct {
  unsigned bits[4];
} s21_decimal;

/* MAIN FUNCTIONS */

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//

int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

//

int s21_from_decimal_to_int(s21_decimal decimal_num, int *integer_num);
int s21_from_int_to_decimal(int integer_num, s21_decimal *decimal_num);
int s21_from_float_to_decimal(float float_num, s21_decimal *decimal_num);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

/* SUPPORT FUNCTIONS */

int is_zero(s21_decimal *num);
void null_decimal(s21_decimal *num);

void print_dec(s21_decimal num);

int get_exp(s21_decimal num);
void set_exp(s21_decimal *num, int exp);

int get_sign(s21_decimal num);
void set_sign(s21_decimal *num, int sign);

unsigned get_bit(s21_decimal num, int bit_pos);

s21_big_decimal convert_from_decimal(s21_decimal num);
int convert_to_decimal(s21_big_decimal num, s21_decimal *res);

void float_scale(int *exp, s21_decimal *decimal_num);

void generalise(s21_decimal *decimal_num);

#endif  // S21_DECIMAL
