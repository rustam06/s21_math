#include <stdio.h>
#include "s21_math.h"

int s21_abs(int x) { return x >= 0 ? x : x * -1; }

long double s21_fabs(double x) {
  long double res = x;
  return x > 0 ? res : res * -1;
}

long double s21_exp(double x) {
  long double e = 1;
  double count = s21_abs(x);
  for (int i = 0; i < count; i++) {
    e *= EXP;
  }
  return x > 0 ? e : 1 / e;
}

long double s21_sin(double x) {
  long double sum, an, n, E = 1e-15;
  sum = x;
  an = x;
  n = 0;

  while (an > E || an < -E) {
    an *= (-1) * x * x / ((2 * n + 2) * (2 * n + 3));
    sum += an;
    n++;
  }

  return sum;
}

long double s21_cos(double x) {
  long double sum, an, n, E = 1e-15;
  sum = 1;
  an = 1;
  n = 1;

  while (an > E || an < -E) {
    an *= (-1) * x * x / ((2 * n - 1) * (2 * n));
    sum += an;
    n++;
  }

  return sum;
}

long double s21_pow(double base, double exp) {
  long double res = 1;
  double count = s21_abs(exp);
  while (count) {
    res *= base;
    count--;
  }
  return exp >= 0 ? res : 1 / res;
}
