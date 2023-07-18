#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    unsigned long long ull;
    unsigned char uc[8];
} ulonglong_uchar;

ulonglong_uchar parseString(char* string){
    ulonglong_uchar ull;
    long long number = 0;
    for(int i=0; i < strlen(string); i++){
        number *= 10;
        number += string[i] - '0';
    }

    for(int i=0; i < 8; i++){
        ull.uc[i] = number % 256;
        number /= 256;
    }
    return ull;
}

int main(void){
    char string[128];
    ulonglong_uchar ull;

    scanf( "%s" , string);
    ull = parseString(string);
    printf( "%I64u\n" , ull.ull);
}