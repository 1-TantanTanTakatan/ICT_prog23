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
#include <string.h>

int main(void){
    int num;
    char str[128] = "";
    scanf( "%d" , &num);

    char buf[128];
    while(num > 0){
        strcpy(buf, str);
        strcpy(str, "");
        
        str[0] = num % 10 + '0';
        str[1] = '\0';
        strcat(str, buf);
        num /= 10;
    }

    printf( "%s\n" , str);
    return 0;
}