/*
 ============================================================================
 Name        : ex38.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
int getDays(int month);
char* month_name(int n);
int main(void) {
    int a, b;
    int count = 0;

    printf( "Input number a (1 <= a <= 3):");
    scanf( "%d" , &a);
    printf( "Input number b (1 <= b <= 3):");
    scanf( "%d" , &b);

    printf( "3a+b:" );
    count += getDays(3*a+b);
    printf( "a+2b:" );
    count += getDays(a+2*b);
    printf( "ab+2:" );
    count += getDays(a*b+2);
    printf( "4a-b:" );
    count += getDays(4*a-b);
    printf( "%d\n" , count);
    return 0;
}

int getDays(int month){
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf( "%s\n" , month_name(month));
    return day[month-1];
}

char* month_name(int n){
    char* name[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return name[n-1];
}