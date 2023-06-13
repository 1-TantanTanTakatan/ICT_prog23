/*
 ============================================================================
 Name        : ex35.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int binarySearch(int data[], int key);
int main(void) {
    int data[SIZE] = {
        0, 1, 2, 4, 5, 6, 7, 9, 10, 12, 13, 15, 16, 17, 18, 19, 20, 21,
        23, 26, 27, 28, 29, 30, 31, 33, 34, 35, 37, 38, 39, 40, 41, 42, 44, 46,
        47, 48, 49, 51, 52, 53, 54, 55, 56, 57, 59, 60, 61, 63, 64, 65, 67, 68,
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 83, 84, 85, 86, 87, 89, 90, 91,
        92, 93, 94, 95, 96, 97, 98, 99, 101, 102, 104, 105, 107, 108, 110,
        111, 112, 113, 114, 115, 117, 118, 119, 120, 123, 124, 125, 127};
    int average = 0;

    for(int i=0; i < 128; i++){ 
       average += binarySearch(data, i);
    }
    average /= 128;
    printf( "Ave: %d\n" , average);

    return 0;
}

int binarySearch(int data[], int key){
    int lw, md, up, count;
    lw = 0;
    up = SIZE - 1;
    count = 0;

    while (lw <= up){
        count++;
        md = (lw + up) / 2;
        if (data[md] == key){
            printf("key = %3d, index = %3d, count = %d\n", key, md, count);
            return count;
        }else if (data[md] < key){
            lw = md + 1;
        }else{
            up = md - 1;
        }
    }

     printf("key = %3d is not found, count = %d\n", key, count);
     return count;
}