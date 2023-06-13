/*
 ============================================================================
 Name        : ex34.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void dayToMonth(int d, int *month, int *day);
int main(void) {
    int birthday[SIZE];
    int month, date, sum;

    srand((unsigned)time(NULL));
    for(int i=0; i < SIZE; i++){
        birthday[i] = rand() % 365 + 1;
    }

    for(int i=0; i < SIZE; i++){
        for(int j=i+1; j < SIZE; j++){
            if(birthday[i] > birthday[j]){
                int tmp = birthday[i];
                birthday[i] = birthday[j];
                birthday[j] = tmp;
            }
        }
    }

    for(int i=0; i < SIZE; i++){
        for(int j=i+1; j < SIZE; j++){
            if(birthday[i] != birthday[j]){
                sum = j - i;
                i = j;
                break;
            }else if(j == SIZE-1){
                sum = j - i;
            }
        }
        if(sum > 1){
            dayToMonth(birthday[i], &month, &date);
            printf( "日数%d, %d月%d日, %d人\n" , birthday[i-1], month, date, sum);
        }
    }

    return 0;
}

void dayToMonth(int d, int *month, int *date){
    int m;
    int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(m=0; m < 12; m++){
        d -= year[m];
        if(d<=0){
            break;
        }
    }
    *date = d + year[m++];
    *month = m;
}