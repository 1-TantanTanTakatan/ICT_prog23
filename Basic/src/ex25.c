/*
 ============================================================================
 Name        : ex25.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
int addstring(char str_out[], char str_a[], char str_b[]);
int main(void) {
    char str_a[100], str_b[100], str_out[200];
    int length;

    scanf( "%s" , str_a);
    scanf( "%s" , str_b);
    length = addstring(str_out, str_a, str_b);
    printf( "%s\n" , str_out);
    printf( "%d\n" , length);
    return 0;
}

int addstring(char str_out[], char str_a[], char str_b[]){
    int lengthA = strlen(str_a);
    int lengthB = strlen(str_b);
    for(int i=0; i < lengthA; i++) {
        str_out[i] = str_a[i];
    }
    str_out[lengthA] = ' ';
    for(int i=0; i <= lengthB; i++) {
        str_out[lengthA+i+1] = str_b[i];
    }
    return strlen(str_out);
}