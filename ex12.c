/*
 ============================================================================
 Name        : ex12.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int array[6] = {1, 2, 3, 4, 5, 6};
    printf( "Initial array:" );
    for(int i=0; i < 6; i++){
        printf( " %d" , array[i]);
    }
    printf( "\n" );
    printf( "Inversed array:" );
    for(int i=0; i < 6; i++){
        printf( " %d" , array[5-i]);
    }
    printf( "\n" );
    return 0;
}
