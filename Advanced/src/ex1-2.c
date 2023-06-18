/*
 ============================================================================
 Name        : ex1-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main(void){
    long long int num;
    scanf( "%I64d" , &num);
    printf( "%I64d\n" , num * num);
    return 0;
}
