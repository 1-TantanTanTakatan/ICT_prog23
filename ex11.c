/*
 ============================================================================
 Name        : ex11.c
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

    printf( "Input a natural number less than 10:" );
    scanf( "%d" , &num);

    for(int i=0; i < num; i++){
        for(int j=1; j < num-i; j++){
            printf( " " );
        }

        int k = 1;
        while(k <= i){
            printf( "%d" , k);
            k++;
        }
        printf( "%d", k);
        while(k > 1){
            k--;
            printf( "%d" , k);
        }
        printf( "\n" );
    } 
    return 0;
}
