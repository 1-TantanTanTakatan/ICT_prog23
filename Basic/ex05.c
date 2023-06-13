/*
 ============================================================================
 Name        : ex05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int year;

    printf( "Year?" );
    scanf( "%d" , &year);
    printf( "Year: %d\n" , year);

    if(year%400==0 || (year%4==0 && year%100!=0)){
        printf( "%d is a leap year\n" , year);
    }else{
        printf( "%d is a normal year\n" , year);
    }
    return 0;
}
