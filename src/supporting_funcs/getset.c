#include "s21_decimal.h"

int get_exp(s21_decimal num) { return (num.bits[3] & EXP_MASK) >> 16; }

int get_sign(s21_decimal num) { return (num.bits[3] & SIGN_MASK); }

unsigned get_bit(s21_decimal num, int bit_pos) {
  unsigned bit = 0;
  unsigned bit_mask = 1 << (bit_pos % 32);
  bit = (bit_mask & num.bits[bit_pos / 32]) >> (bit_pos % 32);
  return bit;
}

void set_exp(s21_decimal *num, int exp) {
  int mask = exp << 16;
  num->bits[3] &= ~EXP_MASK;
  num->bits[3] |= mask;
}

void set_sign(s21_decimal *num, int sign) {
  num->bits[3] &= ~SIGN_MASK;
  num->bits[3] |= (sign << 31);
}

int get_big_exp(s21_big_decimal num) { return (num.bits[7] & EXP_MASK) >> 16; }

void set_big_exp(s21_big_decimal *num, int exp) {
  int mask = exp << 16;
  num->bits[7] &= ~EXP_MASK;
  num->bits[7] |= mask;
}

int get_big_sign(s21_big_decimal num) {
  return ((num.bits[7] & SIGN_MASK) >> 31);
}

void set_big_sign(s21_big_decimal *num, int sign) {
  num->bits[7] &= ~SIGN_MASK;
  num->bits[7] |= (sign << 31);
}

int set_big_bit(s21_big_decimal *num, int bit_pos, int bit) {
  int bit_mask = 1 << (bit_pos % 32);
  if (bit == 0) num->bits[(bit_pos / 32)] &= ~bit_mask;
  if (bit == 1) num->bits[(bit_pos / 32)] |= bit_mask;
  return bit;
}

int get_big_bit(s21_big_decimal num, int bit_pos) {
  unsigned int bit = -1;
  unsigned int bit_mask = 1 << (bit_pos % 32);
  bit = (bit_mask & num.bits[(bit_pos / 32)]) >> (bit_pos % 32);
  return bit;
}
