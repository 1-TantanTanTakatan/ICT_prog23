/*
 ============================================================================
 Name        : ex45.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#define NUM 100
int main(void) {
    FILE *fp;
    int num = 0;
    double aveH = 0, aveW = 0;

    fp = fopen("ex45.txt", "r");

    if(fp == NULL){
        exit(errno);
    }else{
        char name[20];
        double height, weight;
        while(fscanf(fp, "%s", name) != -1){
            num++;
            fscanf(fp, "%lf,", &height);
            fscanf(fp, "%lf", &weight);
            aveH += height;
            aveW += weight;
        }
        aveH /= num;
        aveW /= num;
        printf("Ave.\t%.2f\t%.2f\n", aveH, aveW);
        fclose(fp);
    }
    return 0;
}