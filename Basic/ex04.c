/*
 ============================================================================
 Name        : ex04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int year, result;

    printf( "Year?" );
    scanf( "%d" , &year);
    printf( "Year: %d\n" , year);

    printf( "Leap year(1)/normal year(0): ");
    result = (year%400==0 || (year%4==0 && year%100!=0)) ? 1 : 0;
    printf( "%d\n" , result);
    return 0;
}
