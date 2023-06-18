/*
 ============================================================================
 Name        : ex41.c
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
void quick_sort(float a[], int left, int right);
int partition(float a[], int left, int right);
int main(void) {
    float data[10];
    int n=10;
    set_data(data, n, 0);
    print_data(data, n);
    quick_sort(data, 0, n-1);
    print_data(data,n);
    return 0;
}

void quick_sort(float a[], int left, int right){
    int mid;
    if (left < right){
        mid = partition(a, left, right);
        printf("left: %d-%d\n", left, mid);
        quick_sort(a, left, mid);
        printf("right: %d-%d\n", mid+1, right);
        quick_sort(a, mid+1, right);
    }
}

int partition(float a[], int left, int right){
    float pivot, swap;
    int i,j;
    pivot = a[left];
    i = left;
    j = left - 1;
    while(1){
        a[i] = a[i+1];
        if(a[i] <= pivot){
            j++;
            for(int k=i; k > j; k--){
                swap = a[k];
                a[k] = a[k-1];
                a[k-1] = swap;
            }
        }
        if(++i == right){
            a[right] = pivot;
            return j;
        }
    }
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