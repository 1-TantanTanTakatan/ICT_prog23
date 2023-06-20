/*
 ============================================================================
 Name        : ex27.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float ff(float x);
int main(void) {
    float c, x = 2;
    while(fabsf((c=ff(x))-x) > 0.001){
        x=c;
    }
    return 0;
}

float ff(float x){
    float a, b, c;
    a = 2*x*x*x + 1;
    b = 3*x*x + 1;
    c = a / b;
    printf("x=%f, error=%f\n", c, fabsf(c-x));
    return c;
}