/*
 ============================================================================
 Name        : ex2-2-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void quick_sort(long long int* count_comp, long long int* count_swap, float a[], int left, int right);
int partition(long long int* count_comp, long long int* count_swap, float a[], int left, int right);
float my_random(float lower, float upper);
void set_data(float a[], int n, int seed);
void print_data(float a[], int n);
int main(int argc, char** argv) {
    float* data;
    int size;
    double ave_comp = 0;
    double ave_swap = 0;

    if(argc!=2){
        printf( "The number of Arguments Error\n" );
        return 1;
    }

    size = atoi(argv[1]);
    data = malloc(sizeof(float)*size);
    if(data == NULL){
        printf( "Malloc Error\n" );
        return 1;
    }
    for(int i=0; i < N; i++){
        long long int count_comp = 0;
        long long int count_swap = 0;

        set_data(data, size, i);
        quick_sort(&count_comp, &count_swap, data, 0, size-1);
        print_data(data, size);

        ave_comp += count_comp / N;
        ave_swap += count_swap / N;
    }

    printf( "The Average of Comparisons: %f, " , ave_comp);
    printf( "The Average of Swaps: %f\n" , ave_swap);
    free(data);
    return 0;
}

void quick_sort(long long int* count_comp, long long int* count_swap, float a[], int left, int right){
    int mid;
    if (left < right){
        mid = partition(count_comp, count_swap, a, left, right);
        quick_sort(count_comp, count_swap,a, left, mid);
        quick_sort(count_comp, count_swap,a, mid+1, right);
    }
}

int partition(long long int* count_comp, long long int* count_swap, float a[], int left, int right){
    float pivot, swap;
    int i,j;
    pivot = a[left];
    i = left;
    j = left - 1;
    while(1){
        (*count_comp)++;
        (*count_swap)++;

        a[i] = a[i+1];
        if(a[i] <= pivot){
            j++;
            for(int k=i; k > j; k--){
                (*count_swap)++;
                swap = a[k];
                a[k] = a[k-1];
                a[k-1] = swap;
            }
        }
        if(++i == right){
            (*count_swap)++;
            a[right] = pivot;
            return j;
        }
    }
}

void set_data(float a[], int n, int seed){
    int i;
    srand(seed);
    for(i=0; i<n; i++){
        a[i]=my_random(0.0, 10000.0);
    }
}

float my_random(float lower, float upper){
    float r;
    r = (upper -lower)*rand()/(RAND_MAX)+lower;
    return r;
}

void print_data(float a[], int size){
    printf( "p[0]: %f, " , a[0]);
    printf( "p[%d]: %f, " , size / 2, a[size/2]);
    printf( "p[%d]: %f\n" , size - 1, a[size-1]);
}