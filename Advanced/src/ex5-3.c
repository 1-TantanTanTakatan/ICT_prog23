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

void print_matrix(int n, int mat[][n]){
    for(int i=0; i < n; i++){
        printf( "%d" , mat[i][0]);
        for(int j=1; j < n; j++){
            printf( " %d" , mat[i][j]);
        }
        printf( "\n" );
    }
}

void square_matrix(int n, int mat[][n]){
    int temp[n][n];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            temp[i][j] = 0;
            for(int k=0; k < n; k++){
                temp[i][j] += mat[i][k] * mat[k][j];
            }
        }
    }
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            mat[i][j] = temp[i][j];
        }
    }
}

int main(){
    int n;
    printf( "Size:" );
    scanf( "%d" , &n);

    int m[n][n];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            m[i][j] = i * n + j;
        }
    }

    printf( "M:\n" );
    print_matrix(n, m);

    printf( "M^2\n" );
    square_matrix(n, m);
    print_matrix(n, m);

    printf( "M^4\n" );
    square_matrix(n, m);
    print_matrix(n, m);
    return 0;
}