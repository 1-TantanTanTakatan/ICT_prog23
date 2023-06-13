/*
 ============================================================================
 Name        : ex33.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DataNum 6

int datalist[DataNum] = {98, 140, 84, 28, 42, 126};

int gcd(int a, int b);
int gcd_list(int lst[], int index);
int main(void) {
    printf( "gcd = %d\n" , gcd_list(datalist, DataNum));
    return 0;
}

int gcd(int a, int b){
    for(int i=1; i <= a/2; i++){
        int n = a / i;
        if(a%n==0 && b%n==0){
            return n;
        }
    }
    return 1;
}

int gcd_list(int lst[], int index){
    if(index == 1) {
        return lst[0];
    }else{
        return gcd(lst[index-1], gcd_list(lst, index-1));
    }
}