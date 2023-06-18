/*
 ============================================================================
 Name        : ex1-4-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#define SIZE 200

int linearSearch(int data[], int key);
int main(void) {
    int data_orig[100] = {
        0, 1, 2, 4, 5, 6, 7, 9, 10, 12, 13, 15, 16, 17, 18, 19, 20, 21,
        23, 26, 27, 28, 29, 30, 31, 33, 34, 35, 37, 38, 39, 40, 41, 42, 44, 46,
        47, 48, 49, 51, 52, 53, 54, 55, 56, 57, 59, 60, 61, 63, 64, 65, 67, 68,
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 83, 84, 85, 86, 87, 89, 90, 91,
        92, 93, 94, 95, 96, 97, 98, 99, 101, 102, 104, 105, 107, 108, 110,
        111, 112, 113, 114, 115, 117, 118, 119, 120, 123, 124, 125, 127};
    int data[SIZE];

    for(int i=0; i < 100; i++){
        data[i] = data_orig[i];
        data[i+100] = data_orig[i] + 128;
    }
    double average = 0;

    for(int i=0; i < 256; i++){ 
       average += linearSearch(data, i);
    }
    average /= 256;
    printf( "Ave: %f\n" , average);

    return 0;
}

int linearSearch(int data[], int key){
    int count = 0;

    for (int i=0; i < SIZE; i++){
        count++;
        if (data[i] == key){
            printf("key = %3d, index = %3d, count = %d\n", key, i, count);
            return count;
        }
    }

     printf("key = %3d is not found, count = %d\n", key, count);
     return count;
}