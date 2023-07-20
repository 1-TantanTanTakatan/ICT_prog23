#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE* fp = fopen("ex9-1.txt", "w");
    srand(1);
    for(int i=0; i < 1000; i++){
        int num = rand() % 10000;
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);
    return 0;
}