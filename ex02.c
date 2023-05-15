/*
 ============================================================================
 Name        : ex02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main(void){
    printf( "%d %d\n" , 14/5, 14%5);

    int x1, x2, y1, y2;
    x1 = x2 = y1 = y2 = 0;
    for(int i=0; i < 3; i++) {
    	y1 = ++x1;
    	y2 = x2++;
    	printf( "x1=%d, x2=%d, y1=%d, y2=%d\n" , x1, x2, y1, y2);
    }

    int a = 4;
    printf( "%d %d\n" , a<<1, a>>2); // a<<1 = 1000, a>>2 = 0001

    return 0;
}
