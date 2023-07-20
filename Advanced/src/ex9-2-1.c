#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE* fp = fopen("ex9-2.dat", "wb");
    srand(1);
    for(int i=0; i < 1000; i++){
        short int x = rand() % 10000;
        fwrite(&x, 2, 1, fp);
    }
    fclose(fp);
    return 0;
}