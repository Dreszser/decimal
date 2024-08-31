# Decimal

Implementation of s21_decimal.a library that allows to work with "decimal" data type in C language. Educational project written in School21 - school for programmers by Sber.

## Decimal data type

The Decimal value type represents decimal numbers from positive 79,228,162,514,264,337,593,543,950,335 to negative 79,228,162,514,264,337,593,543,950,335. The default value of a Decimal is 0. The Decimal value type is suitable for financial calculations that require a large number of significant integral and fractional digits and that do not have rounding errors. The Decimal type does not eliminate the need for rounding. Rather, it minimizes rounding errors.

The binary representation of a Decimal value consists of a 1-bit sign, a 96-bit integer, and a scaling factor that is used to divide the 96-bit integer and specify what portion of it is a Decimal fraction. The scaling factor is implicitly the number 10 raised to an exponent between 0 and 28. Therefore, the binary representation of a Decimal value has the form ((-2^96 to 2^96) / 10^(0 to 28)), where -(2^96-1) is equal to MinValue and 2^96-1 is equal to MaxValue.

## Build

- To build a static s21_decimal.a library use Makefile target ``` make all ``` or simply ``` make ```
- To use implemented functions you can create ``` main.c ``` file and run ``` make test ``` target
- You can also run ``` make gcov_report ``` to get html coverage report and run tests, but you will need check and gcovr installed
- (Alternative)Run dockerfile using ``` run.sh ``` script in the "Docker" directory ``` sudo bash run.sh ```, it will create coverage report without the need to install all the libraries yourself
