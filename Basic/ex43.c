/*
 ============================================================================
 Name        : ex43.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
    int num[10] = {};
    char ch;
    while((ch = getchar()) != EOF){
        num[ch-'0']++;
    }
    
    printf( "Frequency of each number\n" );
    for(int i=0; i < 10; i++){
        printf( "'%d' : %d\n" , i, num[i]);
    }
    return 0;
}