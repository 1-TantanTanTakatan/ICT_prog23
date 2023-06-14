/*
 ============================================================================
 Name        : ex36.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char str1[21], str2[6];
    printf( "文字列A:");
    scanf( "%s" , str1);
    printf( "文字列B:");
    scanf( "%s" , str2);

    while(strlen(str1) < 20) {
        strncat(str1, str2, 20 - strlen(str1));
    }
    printf( "%s\n" , str1);
    return 0;
}