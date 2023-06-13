/*
 ============================================================================
 Name        : ex03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    double x, y, r, theta;

    printf( "x?" );
    scanf( "%lf" , &x);
    printf( "y?" );
    scanf( "%lf" , &y);

    printf( "(x, y) = (%.2f, %.2f)\n" , x, y);

    r = sqrt(x*x + y*y);
    theta = atan(y / x) * 180 / M_PI;
    printf( "(r, theta(deg)) = (%.2f, %.2f)\n" , r, theta);

    return 0;
}
