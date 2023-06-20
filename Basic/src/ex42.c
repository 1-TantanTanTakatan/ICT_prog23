/*
 ============================================================================
 Name        : ex42.c
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
void merge_sort(float a[], int left, int right);
int partition(float a[], int left, int right);
int main(void) {
    float data[10] ;
    int n=10;
    set_data(data, n, 0);
    print_data(data, n);
    merge_sort(data, 0, n-1);
    print_data(data,n);
    return 0;
}

void merge_sort(float a[], int left, int right){
    int mid, i, j, k;
    float temp[10];
    if(left>=right)
        return;
    mid = (left+right)/2;
    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    for (i=left; i<=mid; i++)
        temp[i]=a[i];
    for (i=mid+1, j=right; i<= right; i++,j--)
        temp[i]=a[j];

    i = left;
    j = right;
    for(k=left; k <= right; k++){
        if(temp[i] < temp[j]){
            a[k] = temp[i];
            i++;
        }else{
            a[k] = temp[j];
            j--;
        }
    }
    printf( "%d-%d\n" , left, right);
    print_data(a, 10);
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