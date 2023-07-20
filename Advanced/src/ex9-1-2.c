#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE* fp = fopen("ex9-1.txt", "r");
    int sum = 0;
    for(int i=0; i < 1000; i++){
        int num;
        fscanf(fp, "%d", &num);
        sum += num;
    }
    printf( "Sum: %d\n" , sum);
    fclose(fp);
    return 0;
}