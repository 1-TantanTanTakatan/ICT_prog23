#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void){
    clock_t start, end;
    FILE* fp;

    fp = fopen("test.bin", "wb"); //バイナリモード
    start = clock();
    for(int i=0 ; i < 100000; i++){
        srand(1);
        char c = rand() % 256;
        fputc(c, fp);
    }
    end = clock();
    printf( "No fflush 実行時間: %f[s]\n" , (double) (end - start) / CLOCKS_PER_SEC);
    fclose(fp);

    fp = fopen("test.bin", "wb"); //バイナリモード
    start = clock();
    for(int i=0 ; i < 100000; i++){
        srand(1);
        char c = rand() % 256;
        fputc(c, fp);
        fflush(fp);
    }
    end = clock();
    printf( "fflush 実行時間: %f[s]\n" , (double) (end - start) / CLOCKS_PER_SEC);
    fclose(fp);
}