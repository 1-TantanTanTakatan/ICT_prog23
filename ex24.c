/*
 ============================================================================
 Name        : ex24.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
int substring(char str_out[], char str_in[], int start, int len);
int main(void) {
    char str_in[100], str_out[100];
    int start, length;

    scanf( "%s" , str_in);
    scanf( "%d" , &start);
    scanf( "%d" , &length);
    length = substring(str_out, str_in, start, length);
    printf( "%s\n" , str_out);
    printf( "%d\n" , length);
    return 0;
}

int substring(char str_out[], char str_in[], int start, int len){
    int length = (start + len - 1 < strlen(str_in))? len : strlen(str_in)-start+1;
    for(int i=0; i < length; i++) {
        str_out[i] = str_in[start+i-1];
    }
    str_out[length] = '\0';
    return length;
}