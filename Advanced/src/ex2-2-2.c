/*
 ============================================================================
 Name        : ex2-2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define SIZE 20000

float my_random(float lower, float upper);
void set_data(float a[], int size, int seed);
void print_data10(float a[], int size);
int main(void) {
    float data[SIZE];

    for(int i=0; i < N; i++){
        printf( "%d回目\n" , i+1);
        set_data(data, SIZE, (unsigned) time(NULL) + i*1000);
        print_data10(data, SIZE);
        printf("\n" );
    }
    return 0;
}

void set_data(float a[], int size, int seed){
    int i;
    srand(seed);
    for(i=0; i < size; i++){
        a[i]=my_random(0.0, 10000.0);
    }
}

float my_random(float lower, float upper){
    float r;
    r = (upper -lower)*rand()/(RAND_MAX)+lower;
    return r;
}

void print_data10(float a[], int size){
    printf( "最初の10個\n");
    for (int i=0; i < 10; i++){
        printf("%8.2f\n", a[i]);
    }

    printf( "最後の10個\n");
    for (int i=0; i < 10; i++){
        printf("%8.2f\n", a[size-10+i]);
    }
}