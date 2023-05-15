/*
 ============================================================================
 Name        : ex26.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
void func(float a[][4], float b[][4], float seki[][4]);
void printmatrix(float matrix[][4]);
int main(void) {
    float matrix[4][4], buffer1[4][4], buffer2[4][4];
    int number;

    for(int i=0; i < 4; i++){
        for(int j=0; j < 4; j++){
            printf( "C[%d][%d]=" , i, j);
            scanf( "%f" , &matrix[i][j]);
        }
    }
    printf( "n=" );
    scanf( "%d" , &number);
    if(number < 2){
        printf( "number error" );
        return -1;
    }

    func(matrix, matrix, buffer2);
    for(int i=2; i < number; i++){
        if(i%2){
            func(matrix, buffer1, buffer2);
        }else{
            func(matrix, buffer2, buffer1);
        }
    }
    printf( "C^%d\n" ,number);
    if(number%2){
        printmatrix(buffer1);
    }else{
        printmatrix(buffer2);
    }
    return 0;
}

void func(float a[][4], float b[][4], float seki[][4]){
    for(int i=0; i < 4; i++){
        for(int j=0; j < 4; j++){
            seki[i][j] = 0;
            for(int k=0; k < 4; k++){
                seki[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printmatrix(float matrix[][4]){
    for(int i=0; i < 4; i++){
        printf( "%.2f" , matrix[i][0]);
        for(int j=1; j < 4; j++){
            printf( " %.2f" , matrix[i][j]);
        }
        printf( "\n" );
    }
}