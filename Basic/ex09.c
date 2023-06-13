/*
 ============================================================================
 Name        : ex09.c
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

    do{
        printf( "n:" );
        scanf( "%d" , &num);
    }while(num >= 0);
    printf( "%d\n" , num);    
    return 0;
}
