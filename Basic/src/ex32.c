/*
 ============================================================================
 Name        : ex32.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double func(double x, int n);
int fact(int n);
int main(void) {
    int min = 1;
    double y, error;
    double ans = exp(1.0);

    printf( "n\tfx(n)\texp(1)\t|exp(1)-fx(n)|\n" );
    for(int n=1; n <= 10; n++){
        y = func(1.0, n);
        error = fabs(y-ans);
        printf( "%d\t%.6f\t%.6f\t%.6f\n" , n, y, ans, error);

        if(error >= 0.01){
            min = n + 1;
        }
    }
    printf( "Min N = %d\n" , min);
    return 0;
}

double func(double x, int n){
    if(n == 0){
        return 1;
    }else{
        return func(x, n-1) + pow(x, n) / fact(n);
    }
}

int fact(int n){
    if(n == 0){
        return 1;
    }else{
        return fact(n-1) * n;
    }
}