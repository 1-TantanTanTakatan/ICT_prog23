/*
 ============================================================================
 Name        : ex21.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int power(int base, int n);
int main(void) {
    int base, num;
    printf("Input base:");
    scanf("%d" , &base);
    printf("Input num:");
    scanf("%d" , &num);
    printf("%d\n" , power(base, num));
    return 0;
}

int power(int base, int n){
    int i, p;
    p = 1;
    for(i=1; i<=n; ++i){
        p = p * base;
    }
    return p;
}