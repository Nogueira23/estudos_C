#include "complexos.h"
#include <stdio.h>
#include <math.h>

complexo new_complexo(float real, float imag){
    complexo c;
    c.real = real;
    c.imag = imag;
    return c;
}

complexo sum_complexo(complexo a, complexo b){
    return new_complexo(a.real + b.real, a.imag + b.imag);
}

complexo complexo_le(){
    complexo a;
    scanf("%f %f", &a.real, &a.imag);
    return a;
}

void complexo_imprime(complexo a){
    printf("%f + i%f", a.real, a.imag);
    return;
}

float absolute_complexo(complexo a){
    float modulo;
    modulo = sqrt(a.real*a.real + a.imag*a.imag);
    return modulo;
}