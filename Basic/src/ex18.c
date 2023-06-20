/*
 ============================================================================
 Name        : ex18.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int score[4][3] = {{80, 90, 80}, {70, 80, 85}, {95, 60, 70}, {50, 70, 75}};
    char person[4] = {'a', 'b', 'c', 'd'};
    char* subject[3] = {"Math", "English", "Japanese"};
    
    for(int i=0; i < 4; i++){
        double average = 0;
        for(int j=0; j < 3; j++){
            average += score[i][j];
        }
        average /= 3;
        printf( "%cの平均：%f\n" , person[i], average);
    }
    for(int j=0; j < 3; j++){
        double average = 0;
        for(int i=0; i < 4; i++){
            average += score[i][j];
        }
        average /= 4;
        printf( "%sの平均：%f\n" , subject[j], average);
    }
    return 0;
}
