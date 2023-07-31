#include <stdio.h>
#include <stdlib.h>
#define MAXBIT 32

int makeBit(int num, int bits[]){
    int n = 0;
    while(num > 0){
        bits[n] = num & 1;
        num = num >> 1;
        n++;
    }
    return n;
}

unsigned long long power(int b, int x){
    int bits[MAXBIT];
    int n = makeBit(x, bits);
    unsigned long long result = 1;

    for(int i = n; i > 0; i--){
        if(bits[i-1]){
            result *= result * b;
        }else{
            result *= result;
        }
    }
    return result;
}

int main(int argc, char** argv){
    if(argc!=3){
        printf( "The number of Arguments Error\n" );
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf( "%llu\n", power(num1, num2));
    return 0;
}