#include <math.h>
#include <stdio.h>

#include "s21_math.h"

int s21_abs(int x) { return x >= 0 ? x : x * -1; }

long double s21_fabs(double x) {
  long double res = x;
  return x > 0 ? res : res * -1;
}

long double s21_exp(double x) {
  long double e = 1, res = 1;
  int n = 1;
  while (s21_fabs(e) > E) {
    e *= x / n;
    res += e;
    n++;
  }
  return res;
}

// ошибка
long double s21_pow(double base, double exp) {
  long double res = base;
  double count = exp - 1;
  while (count) {
    res *= res;
    count--;
  }
  return res;
}


long double s21_sin(double x) {
  long double sum, an, n;
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

long double s21_asin(double x) {
  long double res = 0;
  if (s21_fabs(x) <= 1) {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return res;
}

long double s21_cos(double x) {
  long double sum, an, n;
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


long double s21_sqrt(double x) {
  long double guess = x;
  long double new_guess;
  if (x > 0) {
    while (1) {
      new_guess = (guess + x / guess) / 2;
      if (s21_fabs(new_guess - guess) < 1e-9) {
        return new_guess;
      }
      guess = new_guess;
    }
  }
  return guess;
}



long double s21_tan(double x) {
  long double res = s21_sin(x) / s21_cos(x);
  return res;
}

long double s21_atan(double x) {
  long double sum = x, an = x;
  const long double PI = 3.141592653589793;
  int n = 1;
  if (s21_fabs(x) > 1) {
    return (x > 0 ? PI / 2 : -PI / 2) - s21_atan(1.0 / x);
  } else {
    while (s21_fabs(an) > E) {
      an *= -x * x * (2.0 * n - 1) / (2.0 * n + 1);
      sum += an;
      n++;
    }
  }
  return sum;
}
