#include "s21_math.h"
#include <stdio.h>
#include <math.h>

int main(void) {
  double x;
  scanf("%lf", &x);
  printf("\nabs == %d / %f\n", s21_abs(x), fabs(x));
  printf("fabs == %.7Lf / %.7f\n", s21_fabs(x), fabs(x));
  printf("pow == %.7Lf / %.7f\n", s21_pow(x, 2), pow(x, 2));
  printf("sqrt == %.7Lf / %.7f\n", s21_sqrt(x), sqrt(x));
  printf("sin == %.7Lf / %.7f\n", s21_sin(x), sin(x));
  printf("exp == %.7Lf / %.7f\n", s21_exp(x), exp(x));
  printf("cos == %.7Lf / %.7f\n", s21_cos(x), cos(x));
  printf("tan == %.7Lf / %.7f\n", s21_tan(x), tan(x));
  printf("atan == %.7Lf / %.7f\n", s21_atan(x), atan(x));
  printf("asin == %.7Lf / %.7f\n", s21_asin(x), asin(x));
  return 0;
}
