/*
 ============================================================================
 Name        : ex3-2-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

unsigned int stringToIntX(char* str);
int main(void){
    char string[128];
    scanf( "%s" , string);
    unsigned int n = stringToIntX(string);
    printf( "%x\n" , n);
}

unsigned int stringToIntX(char* str){
    int num = 0;
    int i = 0;
    while(str[i] != '\0'){
        num *= 16;
        if(str[i] >= '0' && str[i] <= '9'){
            num += str[i] - '0';
        }else if(str[i] >= 'a' && str[i] <= 'f'){
            num += str[i] - 'a' + 10;
        }else if(str[i] >= 'A' && str[i] <= 'F'){
            num += str[i] - 'A' + 10;
        }
        i++;
    }
    return num;
}