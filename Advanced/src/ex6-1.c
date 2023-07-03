#include<stdio.h>
#include<stdlib.h>

void print_pointer(int* a[10]){
    for(int i=0; i < 10; i++){
        printf( "a[%d] = %p\n" , i, a[i]);
    }
}

int main(){
    // A
    int *a[10];
    for(int i=0; i < 10; i++){
        a[i] = NULL;
    }

    // B
    for(int i=0; i < 5; i++){
        a[i] = malloc(sizeof(int));
    }

    // C
    printf( "C)\n" );
    print_pointer(a);

    // D
    free(a[1]);
    free(a[2]);
    free(a[4]);
    a[1] = a[2] = a[4] = NULL;

    // E
    printf( "E)\n" );
    print_pointer(a);

    // F
    for(int i=5; i < 10; i++){
        a[i] = malloc(sizeof(int));
    }

    // G
    printf( "G)\n" );
    print_pointer(a);

    // H
    free(a[0]);
    free(a[3]);
    for(int i=5; i < 10; i++){
        free(a[i]);
    }
}