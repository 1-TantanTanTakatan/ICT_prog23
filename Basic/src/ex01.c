/*
 ============================================================================
 Name        : ex01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main(void){
    char c = 'A';
    int a = 500;
    double pi = 3.141592;
    double x = 2.444;
    double y = 5298.754;
    double z = 120.22;

    printf( "%c\n" , c);
    printf( "%d, %o, %x\n" , a, a, a);
    printf( "%f, %.3f, %e\n" , pi, pi, pi*100);
    printf( "%07.2f\n%07.2f\n%07.2f\n" , x, y, z);

    return 0;
}
