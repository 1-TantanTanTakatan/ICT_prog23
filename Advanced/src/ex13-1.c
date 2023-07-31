#include "hugeint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

huge_int* clone_hugeInt(huge_int* num){
    huge_int* result = malloc(sizeof(huge_int) + num->size);
    result->size = num->size;
    for(int i=0; i < result->size; i++){
        result->num[i] = num->num[i];
    }
    return result;
}

char* toString(huge_int* num){
    int digit = 0;
    huge_int* num1 = from_uchar(1);
    huge_int* num10 = from_uchar(10);
    huge_pair hp1 = huge_divide(num, num1);

    while(hp1.q->size > 0){
        digit++;
        huge_pair hp2 = huge_divide(hp1.q, num10);
        free(hp1.q);
        free(hp1.r);
        hp1 = hp2;
    }
    free(hp1.q);
    free(hp1.r);

    char* str = malloc(sizeof(char) * (digit+1));
    for(int i=0; i < digit; i++){
        huge_pair hp = huge_divide(num, num10);
        free(num);
        str[digit-i-1] = hp.r->num[0] + '0';
        num = hp.q;
        free(hp.r);
    }
    str[digit] = '\0';

    free(num);
    free(num10);
    return str;
}

huge_int* fromString(char* str){
    huge_int* num = from_uchar(0);
    huge_int* num10 = from_uchar(10);

    int i = 0;
    while(str[i] != '\0'){
        huge_int* swap = huge_multiply(num, num10);
        free(num);
        huge_int* uc = from_uchar(str[i] - '0');
        num = huge_add(swap, uc);
        free(swap);
        free(uc);
        i++;
    }
    free(num10);
    return num;
}

int main(int argc, char** argv){
    char* str;

    if(argc!=3){
        printf( "The number of Arguments Error\n" );
        return 1;
    }

    huge_int* num1 = fromString(argv[1]);
    huge_int* num2 = fromString(argv[2]);
    huge_int* sum = huge_add(num1, num2);
    free(num1);
    free(num2);

    str = toString(sum);
    printf( "%s\n" , str);
    free(str);
    return 0;
}