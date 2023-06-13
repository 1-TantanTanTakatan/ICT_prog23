/*
 ============================================================================
 Name        : ex23.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
int reverse(char str_out[], char str_in[]);
int main(void) {
    char str_in[100], str_out[100];
    int length;

    scanf("%s" , str_in);
    length = reverse(str_out, str_in);
    printf( "%s\n" , str_out);
    printf("%d\n" , length);
    return 0;
}

int reverse(char str_out[], char str_in[]){
    int length = strlen(str_in);
    for(int i=0; i < length; i++) {
        str_out[i] = str_in[length-i-1];
    }
    str_out[length] = '\0';
    return length;
}