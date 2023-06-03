#include "s21_math.h"
#include <math.h>
#include <stdio.h>

int main(void) { 
    int x = 4;
    printf("\n%.8Lf / %.8f\n", s21_sin(x), sin(x));
    printf("%.8Lf / %.8f", s21_cos(x), cos(x));
    return 0; 
    
    }
