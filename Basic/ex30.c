/*
 ============================================================================
 Name        : ex30.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int func(int x, int y);
int main(void) {
    printf( "\ty\n" );
    printf( "x\t0\t1\t2\t3\t4\t5\t6\t7\t8\n" );
    for(int i=0; i < 4; i++){
        printf( "%d" , i);

        for(int j=0; j < 9; j++){
            printf( "\t%d" , func(i, j));
        }
        printf( "\n" );
    }
}

int func(int x, int y){
    if(x == 0){
        return y + 1;
    }else if(y == 0){
        return func(x-1, 1);
    }else{
        return func(x-1, func(x, y-1));
    }
}