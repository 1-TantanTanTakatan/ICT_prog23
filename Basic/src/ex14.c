/*
 ============================================================================
 Name        : ex14.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    char string[100];
    scanf( "%s" , string);
    for(int i=0; string[i]!='\0'; i++){
        printf( "%c*" , string[i]);
    }
    printf( "\n" );
    return 0;
}
