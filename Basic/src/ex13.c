/*
 ============================================================================
 Name        : ex13.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int score[6];
    double average = 0;
    double sd = 0;

    for(int i=0; i < 6; i++){
        scanf( "%d" , &score[i]);
        average += score[i];
    }
    average /= 6;
    for(int i=0; i < 6; i++){
        sd += (score[i]-average) * (score[i]-average);
    }
    sd /= 6;
    sd = sqrt(sd);
    printf( "Average: %f\nSD: %f\n" , average, sd);
    return 0;
}
