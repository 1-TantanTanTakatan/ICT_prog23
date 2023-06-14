/*
 ============================================================================
 Name        : ex10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int start, end;

    printf( "Input start:" );
    scanf( "%d" , &start);

    printf( "Input end  :" );
    scanf( "%d" , &end);

    for(int i=start; i < end+1; i++){
        if(i%400==0 || (i%4==0 && i%100!=0)){
            printf( "%d\n" , i);
        }
    } 
    return 0;
}
