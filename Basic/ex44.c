/*
 ============================================================================
 Name        : ex44.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define NUM 100
int main(void) {
    FILE *fp1, *fp2;

    fp1 = fopen("ex44.txt", "r");
    fp2 = fopen("result.txt", "w");

    if(fp1 == NULL || fp2 == NULL){
        exit(errno);
    }else{
        for(int i=0; i < 6; i++){
            int num;
            fscanf(fp1, "%d", &num);
            fprintf(fp2, "%d\n", num*2);
        }
        fclose(fp1);
        fclose(fp2);
    }
    return 0;
}