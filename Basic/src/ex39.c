/*
 ============================================================================
 Name        : ex39.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float my_random(float lower, float upper);
void set_data(float a[], int n, int seed);
void print_data(float a[], int n);
int main(void) {
    float data[10], swap;
    int i,j, n=10;
    set_data(data, n, 0);
    print_data(data, n);
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(data[j]>data[j+1]){
                swap = data[j];
                data[j] = data[j+1];
                data[j+1] = swap;
            }
        }
    }
    print_data(data,n);
    return 0;
}

void set_data(float a[], int n, int seed){
    int i;
    srand(seed);
    for(i=0; i<n; i++){
        a[i]=my_random(0.0, 1000.0);
    }
}

float my_random(float lower, float upper){
    float r;
    r = (upper -lower)*rand()/(RAND_MAX)+lower;
    return r;
}

void print_data(float a[], int n){
    int i;
    for (i=0; i<n; i++){
        printf("%8.2f \n",a[i]);
    }
    printf("Total %d data \n", n);
}