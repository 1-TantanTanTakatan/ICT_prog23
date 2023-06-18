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
#define SIZE 20000

void quick_sort(int* count_comp, int* count_swap, float a[], int left, int right);
int partition(int* count_comp, int* count_swap, float a[], int left, int right);
float my_random(float lower, float upper);
void set_data(float a[], int n, int seed);
void print_data10(float a[], int n);
int main(void) {
    float data[SIZE];
    int ave_comp = 0;
    int ave_swap = 0;

    for(int i=0; i < N; i++){
        int count_comp = 0;
        int count_swap = 0;

        set_data(data, SIZE, (unsigned) time(NULL) + i*1000);
        quick_sort(&count_comp, &count_swap, data, 0, SIZE-1);
        print_data10(data, SIZE);

        printf( "The Number of Comparisons: %d\n" , count_comp);
        printf( "The Number of Swaps: %d\n" , count_swap);
        ave_comp += count_comp;
        ave_swap += count_swap;
    }

    ave_comp /= N;
    ave_swap /= N;
    printf( "The Average of Comparisons: %d\n" , ave_comp);
    printf( "The Average of Swaps: %d\n" , ave_swap);

    return 0;
}

void quick_sort(int* count_comp, int* count_swap, float a[], int left, int right){
    int mid;
    if (left < right){
        mid = partition(count_comp, count_swap, a, left, right);
        quick_sort(count_comp, count_swap,a, left, mid);
        quick_sort(count_comp, count_swap,a, mid+1, right);
    }
}

int partition(int* count_comp, int* count_swap, float a[], int left, int right){
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

void print_data10(float a[], int size){
    printf( "First: %.2f" , a[0]);
    for (int i=1; i < 10; i++){
        printf(" %.2f", a[i]);
    }
    printf( "\n" );

    printf( "Last: %.2f" , a[size-10]);
    for (int i=1; i < 10; i++){
        printf(" %.2f", a[size-10+i]);
    }
    printf( "\n" );
}