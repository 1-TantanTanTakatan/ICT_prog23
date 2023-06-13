/*
 ============================================================================
 Name        : ex06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int month;

    printf( "Input month:" );
    scanf( "%d" , &month);

    printf( "This month is " );
    if(month>=3 && month <= 5){
        printf( "spring\n" );
    }else if(month>=6 && month <= 8){
        printf( "summer\n" );
    }else if(month>=9 && month <= 11){
        printf( "autumn\n" );
    }else if(month==12 || month ==1 || month ==2){
        printf( "winter\n" );
    }

    printf( "There are " );
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf( "31" );
            break;
        case 2:
            printf( "28" );
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf( "30" );
            break;
    }
    printf ( " days in this month.\n" );
    return 0;
}
