/*
 ============================================================================
 Name        : ex17.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int row, column;
    int matrix[100][100];

    printf( "Row of Matrix?" );
    fflush(stdout);
    scanf( "%d" , &row);
    printf( "Column of Matrix?" );
    fflush(stdout);
    scanf( "%d" , &column);
    
    for(int i=0; i < row; i++){
        for(int j=0; j < column; j++){
            matrix[i][j] = i%2 ^ j%2;
        }
    }
    for(int i=0; i < row; i++){
        for(int j=0; j < column; j++){
            printf( "%d" , matrix[i][j]);
        }
        printf( "\n" );
    }
    return 0;
}
