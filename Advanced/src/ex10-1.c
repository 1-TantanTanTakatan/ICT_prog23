#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void makeTestFile(){
    FILE *fp = fopen("little2.bin", "wb"); //バイナリモード
    unsigned int number = 0x00030201;
    fputc(number & 0xff, fp);
    fputc(number >> 8 & 0xff, fp);
    fputc(number >> 16 & 0xff, fp);
    number = 0x00010203;
    fputc(number & 0xff, fp);
    fputc(number >> 8 & 0xff, fp);
    fputc(number >> 16 & 0xff, fp);
    fclose(fp);
}

int dump_line20(FILE* fp){
    unsigned char bytes[16]; 
    int n;

    for(int i=0; i < 20; i++){
        n = fread(bytes, sizeof(char), 16, fp);
        if(n == 0){
            return 1;
        }
        for(int j=0; j < 16; j++){
            if(j < n){
                printf( "%02x " , bytes[j]);
            }else{
                printf( "   " );
            }
        }
        printf( " | " );

        for(int j=0; j < 16; j++){
            if(j < n){
                if(bytes[j] >= 20 && bytes[j] <=127){
                    printf( "%c" , bytes[j]);
                }else{
                    printf( " " );
                }
            }else{
                printf( " " );
            }
        }
        printf( " |\n" );
    }
    return 0;
}

int file_dump(char* filename){
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL){
        printf( "No file\n" );
        return -1;
    }

    while(1){
        if(dump_line20(fp)){
            break;
        }
        char answer[64];
        printf( "more ? " );
        scanf( "%s" , answer);
        if(strcmp(answer, "y") != 0){
            break;
        }
    }
    fclose(fp);
    return 0;
}

unsigned long long int readBinaryInt(FILE* fp){
    int bytes[3];

    for (int i = 0; i < 3; i++) {
        bytes[i] = fgetc(fp);
        if (bytes[i] == EOF) {
            fprintf(stderr, "read error!");
            exit(1);
        }
    }
    return bytes[0] | bytes[1] << 8 | bytes[2] << 16;
}

void writeBinaryInt(FILE* fp, unsigned long long int number){
    for(int i=0 ; i < 6; i++){
        fputc(number & 0xff, fp);
        number = number >> 8;
    }
}

int main(void){
    makeTestFile();
    file_dump("little2.bin");
    FILE *fp = fopen("little2.bin", "rb+"); //バイナリモード
    unsigned long long int a, b;
    a = readBinaryInt(fp);
    b = readBinaryInt(fp);
    fseek(fp, 6, SEEK_SET);
    writeBinaryInt(fp, a*b);
    fclose(fp);
    file_dump("little2.bin");
}