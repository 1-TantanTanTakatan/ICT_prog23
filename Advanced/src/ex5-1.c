#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct {
    char str1[3];
    unsigned char num1;
    char str2[7];
    unsigned int num2;
    char str3[10];
} test_t;

int main(){
    int c[3];
    test_t a[3];

    for(int i=0; i < 3; i++){
        printf("address of c[%d] is %p\n", i, &c[i]);
        printf("address of c+%d is  %p\n", i, c+i);
    }
    for(int i=0; i < 3; i++){
        printf("address of a[%d] is %p\n", i, &a[i]);
    }
    return 0;
}