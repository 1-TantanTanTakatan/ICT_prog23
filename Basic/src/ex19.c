/*
 ============================================================================
 Name        : ex19.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int a[2][3] = {{2, 3, 4}, {1, 0, 1}};
    int b[3][2] = {{1, 2}, {1, 0}, {3, 1}};
    int answer[2][2];
    
    for(int i=0; i < 2; i++){
        for(int j=0; j < 2; j++){
            answer[i][j] = 0;
            for(int k=0; k < 3; k++){
                answer[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i=0; i < 2; i++){
        printf( "%d", answer[i][0]);
        for(int j=1; j < 2; j++){
            printf( ", %d", answer[i][j]);
        }
        printf( "\n" );
    }
    return 0;
}
