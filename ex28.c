/*
 ============================================================================
 Name        : ex28.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float ff();
int main(void) {
    ff();
    return 0;
}

float ff(){
    float a, b, c, x;
    a = -1;
    b = 1;
    c = 1;
    do{
        x = c;
        c = (a*(b*b*b+b-1)-b*(a*a*a+a-1)) / ((b*b*b+b-1)-(a*a*a+a-1));
        if((c*c*c+c-1)*(b*b*b+b-1)>0){
            b = c;
        }else{
            a = c;
        }
        printf("x=%f, error=%f\n", c, fabsf(c-x));
    }while(fabsf(c-x) > 0.001);
    return c;
}