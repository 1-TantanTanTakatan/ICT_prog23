#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE* fp = fopen("ex9-2.dat", "rb");
    int sum = 0;
    for(int i=0; i < 1000; i++){
        short int num;
        fread(&num, 2, 1, fp);
        sum += num;
    }
    printf( "Sum: %d\n" , sum);
    fclose(fp);
    return 0;
}