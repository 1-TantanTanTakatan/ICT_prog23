/*
 ============================================================================
 Name        : ex31.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <time.h>
int fibonacci (int n);
int main (void){
    int i;
    double y;
    int fib[45];
    clock_t start1, end1, start2, end2;

    start1 = clock();
    for (i = 2; i <= 45; i++){
        y = (double) fibonacci(i) /fibonacci(i-1);
        printf ("fib(%d) /fib(%d) = %lf \n", i, i-1,y);
    }
    end1 = clock();

    start2 = clock();
    for(i = 1; i <= 45; i++){
        fib[i-1] = fibonacci(i);
    }
    for (i = 1; i < 45; i++){
        y = (double) fib[i] /fib[i-1];
        printf ("fib(%d) /fib(%d) = %lf \n", i, i-1,y);
    }
    end2 = clock();

    printf( "配列を用いない場合\n" );
    printf("Elapsed %ld (ms) \n", end1-start1);
    printf("T(秒)= %f \n", (double)(end1-start1)/CLOCKS_PER_SEC);

    printf( "配列を用いた場合\n" );
    printf("Elapsed %ld (ms) \n", end2-start2);
    printf("T(秒)= %f \n", (double)(end2-start2)/CLOCKS_PER_SEC);
    return 0;
}

int fibonacci (int n) {
    if (n == 0 ) return 0;
    else if (n == 1) return 1;
    else return (fibonacci(n-2)+fibonacci(n-1));
}