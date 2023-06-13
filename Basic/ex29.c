/*
 ============================================================================
 Name        : ex29.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int sum1(int number);
int sum2(int number);
int main(void) {
    int number[3] = {10, 100, 1000};

    printf( "Recursion\n" );
    for(int i=0; i < 3; i++){
        printf( "sum %d = %d\n" , number[i], sum1(number[i]));
    }
    printf( "Non-Recursion\n" );
    for(int i=0; i < 3; i++){
        printf( "sum %d = %d\n" , number[i], sum2(number[i]));
    }
    return 0;
}

int sum1(int number){
    if(number == 0){
        return 0;
    }else{
        return number + sum1(number - 1);
    }
}

int sum2(int number){
    int sum = 0;
    for(int i=0; i < number; i++){
        if(number == 0){
            break;
        }else{
            sum += i + 1;
        }
    }
    return sum;
}