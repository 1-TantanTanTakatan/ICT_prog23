#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
                if(bytes[j] >= 32 && bytes[j] <=127){
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

int main(){
    char filename[64];
    scanf( "%s" , filename);
    file_dump(filename);
}