#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filetype(FILE* fp, char type[3]){
    fseek(fp, 0x0000, SEEK_SET);
    fread(type, 1, 2, fp);
    type[2] = '\0';
}

short pixelBit(FILE* fp){
    short pixelBit;
    fseek(fp, 0x001c, SEEK_SET);
    fread(&pixelBit, 2, 1, fp);
    return pixelBit;
}

int offset(FILE* fp){
    int offset;
    fseek(fp, 0x000a, SEEK_SET);
    fread(&offset, 4, 1, fp);
    return offset;
}

int main(void){
    char filename[64];
    char type[3];
    int correct;

    printf( "filename ? :" );
    scanf( "%s" , filename);

    FILE* fp = fopen(filename, "rb"); //バイナリモード
    if(fp == NULL){
        printf( "Can not open\n" );
        return 1;
    }

    filetype(fp, type);
    correct = (strcmp(type, "BM")==0) + (pixelBit(fp)==24) + (offset(fp)==54);
    if(correct != 3){
        printf( "Number of unsatisfied items = %d.\nDifferent file type.\n" , 3 - correct);
        return 1;
    }
    printf( "OK.\n" );
    return 0;
}