/*
 ============================================================================
 Name        : ex2-2-6.c
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
#define SIZE 60000
#define KIND 4

void start_merge_sort(int* count_comp, int* count_swap, float a[], int size);
void merge_sort(int* count_comp, int* count_swap, float a[], float temp[], int left, int right);
void select_sort(int* count_comp, int* count_swap, float a[], int size);
void countAverage(int size);
void start_quick_sort(int* count_comp, int* count_swap, float a[], int size);
void quick_sort(int* count_comp, int* count_swap, float a[], int left, int right);
int partition(int* count_comp, int* count_swap, float a[], int left, int right);
void bubble_sort(int* count_comp, int* count_swap, float a[], int size);
float my_random(float lower, float upper);
void set_data(float a[], int n, int seed);
void print_data10(float a[], int n);
int main(void) {
    for(int i=1; i <= SIZE/20000; i++){
        countAverage(i*20000);
    }
    return 0;
}

void countAverage(int size){
    float data[SIZE];
    char* str[KIND] = {"バブルソート", "クイックソート", "単純選択ソート", "マージソート"};
    void (*func[KIND])(int*, int*, float[], int) = {bubble_sort, start_quick_sort, select_sort, start_merge_sort};

    printf( "N=%d\n" , size);
    for(int i=0; i < KIND; i++){
        int ave_comp = 0;
        int ave_swap = 0;

        for(int j=0; j < N; j++){
            int count_comp = 0;
            int count_swap = 0;

            set_data(data, size, (unsigned) time(NULL) + j*1000);
            func[i](&count_comp, &count_swap, data, size);
            
            ave_comp += count_comp / N;
            ave_swap += count_swap / N;
        }

        printf( "The Average of Comparisons(%s): %d\n" , str[i], ave_comp);
        printf( "The Average of Swaps(%s): %d\n" , str[i], ave_swap);
    }
}

void start_merge_sort(int* count_comp, int* count_swap, float a[], int size){
    float temp[SIZE];
    merge_sort(count_comp, count_swap, a, temp, 0, size-1);
}

void merge_sort(int* count_comp, int* count_swap, float a[], float temp[], int left, int right){
    int mid, i, j, k;

    if(left>=right)
        return;
    mid = (left+right)/2;
    merge_sort(count_comp, count_swap, a, temp, left, mid);
    merge_sort(count_comp, count_swap, a, temp, mid+1, right);
    for (i=left; i<=mid; i++)
        temp[i]=a[i];
    for (i=mid+1, j=right; i<= right; i++,j--)
        temp[i]=a[j];

    i = left;
    j = right;
    for(k=left; k <= right; k++){
        (*count_comp)++;
        if(temp[i] < temp[j]){
            a[k] = temp[i];
            i++;
        }else{
            a[k] = temp[j];
            j--;
        }
    }
}

void select_sort(int* count_comp, int* count_swap, float a[], int size){
    float swap;
    int min;

    for(int i=0; i < size-1; i++){
        min = i;
        for(int j=i+1; j < size; j++){
            (*count_comp)++;
            if(a[j] < a[min]){
                min=j;
            }
        }
        (*count_swap)++;
        swap = a[i];
        a[i] = a[min];
        a[min] = swap;
    }
}

void start_quick_sort(int* count_comp, int* count_swap, float a[], int size){
    quick_sort(count_comp, count_swap, a, 0, size-1);
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

void bubble_sort(int* count_comp, int* count_swap, float a[], int size){
    float swap;

    for(int i=0; i < size-1; i++){
        for(int j=0; j < size-i-1; j++){
            (*count_comp)++;
            if(a[j] > a[j+1]){
                (*count_swap)++;
                swap = a[j];
                a[j] = a[j+1];
                a[j+1] = swap;
            }
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