/*
 ============================================================================
 Name        : ex3-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

char* intToString(char* str, int num);
int main(void){
    int num;
    char str[128];
    scanf( "%d" , &num);
    printf( "%s\n" , intToString(str, num));
    return 0;
}

char* intToString(char* str, int num){
    int digit = 0;
    int sub = num;
    while(sub > 0){
        digit++;
        sub /= 10;
    }

    for(int i=0; i < digit; i++){
        str[digit-i-1] = num % 10 + '0';
        num /= 10;
    }
    str[digit] = '\0';
    return str;
}