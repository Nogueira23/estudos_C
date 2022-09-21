#include <stdio.h>
#include "complexos.c"
#include <math.h>

int main()
{
    complexo a, b, c;
    a = complexo_le();
    b = complexo_le();
    c = sum_complexo(a, b);
    complexo_imprime(c);
    printf("%f\n", absolute_complexo(c));
    return 0;
}