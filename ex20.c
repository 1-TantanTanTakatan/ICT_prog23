/*
 ============================================================================
 Name        : ex20.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float ftoc(float fahr);
int main(void) {
    float fahr, celsius;
    float lower, upper;
    lower = 0;
    upper = 300;
    do{
        printf("input fahr(%f<=fahr<=%f)",lower,upper);
        scanf("%f",&fahr);
    } while((fahr>upper) || (fahr<lower));

    celsius = ftoc(fahr);
    printf("fahr=%f\tcelsius=%f\n", fahr, celsius);
    return EXIT_SUCCESS;
}

float ftoc(float fahr){
    return 5*(fahr - 32)/9;
}