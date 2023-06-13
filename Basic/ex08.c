/*
 ============================================================================
 Name        : ex08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int num;
    int sum = 0;

    printf( "n:" );
    scanf( "%d" , &num);

    while(num > 0){
        sum += num;
        num--;
    }
    printf( "%d\n" , sum);
    return 0;
}
