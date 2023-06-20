/*
 ============================================================================
 Name        : ex07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    double height, weight, bmi;

    printf( "Height(m)?" );
    scanf( "%lf" , &height);
    printf( "Weight(kg)?" );
    scanf( "%lf" , &weight);

    bmi = weight / height / height;
    printf( "BMI: %f\n" , bmi);

    if(bmi < 18.5){
        printf( "低体重\n" );
    }else if(bmi < 25){
        printf( "普通体重\n" );
    }else if(bmi < 30){
        printf( "肥満(1度)\n" );
    }else if(bmi < 35){
        printf( "肥満(2度)\n" );
    }else if(bmi < 40){
        printf( "肥満(3度)\n" );
    }else{
        printf( "肥満(4度)\n" );
    }
    return 0;
}
