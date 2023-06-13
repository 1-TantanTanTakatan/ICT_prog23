/*
 ============================================================================
 Name        : ex15.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void){
    int holidayinmonth[12] = {7, 6, 5, 5, 8, 4, 6, 5, 6, 6, 6, 4};
    int max, min, odd, even;

    max = holidayinmonth[0];
    min = holidayinmonth[0];
    odd = 0;
    even = 0;
    for(int i=0; i < 12; i++){
        if(holidayinmonth[i]>max){
            max = holidayinmonth[i];
        }
        if(holidayinmonth[i]<min){
            min = holidayinmonth[i];
        }
        if(i%2){
            even += holidayinmonth[i];
        }else{
            odd += holidayinmonth[i];
        }
    }
    printf( "ifを使う場合\n" );
    printf( "最も休日が多い月の休日数：%d\n" , max);
    printf( "最も休日が少ない月の休日数：%d\n" , min);
    printf( "偶数月の休日数の合計：%d\n" , even);
    printf( "奇数月の休日数の合計：%d\n" , odd);
    
    max = 0;
    min = 31;
    odd = 0;
    even = 0;
    for(int i=0; i < 12; i++){
        max = holidayinmonth[i]*(holidayinmonth[i]>max) + max*(holidayinmonth[i]<=max);
        min = holidayinmonth[i]*(holidayinmonth[i]<min) + min*(holidayinmonth[i]>=min);
        even += holidayinmonth[i]*(i%2);
        odd += holidayinmonth[i]*(i%2 == 0);
    }
    printf( "ifを使わない場合\n" );
    printf( "最も休日が多い月の休日数：%d\n" , max);
    printf( "最も休日が少ない月の休日数：%d\n" , min);
    printf( "偶数月の休日数の合計：%d\n" , even);
    printf( "奇数月の休日数の合計：%d\n" , odd);
    return 0;
}
