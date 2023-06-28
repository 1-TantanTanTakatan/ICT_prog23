#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void swap_univ(void* a, void* b, int size){
    char* A = (char*) a;
    char* B = (char*) b;

    for(int i=0; i < size; i++) {
        char temp = *(A+i);
        *(A+i) = *(B+i);
        *(B+i) = temp;
    }
};

void swap2(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    char a = 'A';
    char b = 'B';
    printf( "In main: address of a : %p, address of b : %p\n" , &a, &b);
    swap2(&a, &b);
    printf( "In main: address of a : %p, address of b : %p\n" , &a, &b);
    printf( "a = %c, b = %c\n" , a, b);
}