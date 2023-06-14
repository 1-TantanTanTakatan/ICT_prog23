/*
 ============================================================================
 Name        : ex40.c
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
    float data[10], ins;
    int i,j, n=10;
    set_data(data, n, 0);
    data[0] = 999.99;
    print_data(data, n);
    for(i=1; i<n; i++){
        printf("i=%d\t",i);
        ins = data[i];
        for(j=i;j>=0;j--){
            printf("j=%d ",j);
            if(j==0){
                data[0] = ins;
            }else if(data[j-1]>ins){
                data[j] = data[j-1];
            }else{
                data[j] = ins;
                break;
            }
        }
        printf("\n");
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