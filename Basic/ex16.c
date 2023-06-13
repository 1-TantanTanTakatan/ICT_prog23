/*
 ============================================================================
 Name        : ex16.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#define MAX 100
#define MIN 0
#define RANK 11
#define STEP 10
int main (void) {
    double score;
    int i, table[RANK];
    for (i=0; i < RANK; i++) table[i] = 0;
    while (1) {
        scanf ("%lf", &score);
        if (score < MIN || score > MAX){
            while(1){
                printf( "Really? Yes(1)/No(0):");
                scanf( "%lf" , &score);
                if(score == 0 || score == 1){
                    break;
                }
            }
            if(score){
                break;
            }
        }else{
            i = (int)(score / STEP);
            table[i] ++;
        }
    }
    for (i=0; i < RANK; i++){
        printf( "Rank %d, Freq %d\n" , i, table[i]);
    }
    return 0;
}