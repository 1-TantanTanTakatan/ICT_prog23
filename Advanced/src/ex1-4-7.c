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
#define SIZE 500
#define KIND 2

void countAverage(int data[], int size);
int linearSearch(int data[], int key, int size);
int binarySearch(int data[], int key, int size);
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
        for(int j=1; j <= 5; j++){
            data[i+100*j] = data_orig[i] + 128*j;
        }
    }
    
    for(int i=1; i <= SIZE/100; i++){
        countAverage(data, 100*i);
    }
    return 0;
}

void countAverage(int data[], int size){
    int num = size * 128 / 100;
    char* str[KIND] = {"線形探索", "二分探索"};
    int (*func[KIND])(int[], int, int) = {linearSearch, binarySearch};

    double average = 0;
    for(int i=0;  i < KIND; i++){
        for(int j=0; j < num; j++){ 
            average += func[i](data, j, size);
        }
        average /= num;
        printf( "%s(SIZE=%d) Ave: %f\n" , str[i], size, average);
    }
}

int linearSearch(int data[], int key, int size){
    int count = 0;

    for (int i=0; i < size; i++){
        count++;
        if (data[i] == key){
            return count;
        }
    }

     return count;
}

int binarySearch(int data[], int key, int size){
    int lw, md, up, count;
    lw = 0;
    up = size - 1;
    count = 1;

    while (lw <= up){
        count++;
        md = (lw + up) / 2;
        if (data[md] == key){
            return count;
        }else if (data[md] < key){
            lw = md + 1;
        }else{
            up = md - 1;
        }
    }

     return count;
}