#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   unsigned char b;
   unsigned char g;
   unsigned char r;
} rgb_t;

typedef struct {
    char type[3];
    int size;
    int reserve;
    int offset;
} file_header;

typedef struct {
    int header_size;
    int x_size;
    int y_size;
    short plane;
    short pixelBit;
    int compress;
    int size;
    int dpi;
} bitmapinfo_header;

void read_fileHeader(FILE* fp, file_header* fh){
    fseek(fp, 0x0000, SEEK_SET);
    fread(fh->type, 1, 2, fp);
    fh->type[2] = '\0';
    fread(&(fh->size), 12, 1, fp);
}

void write_fileHeader(FILE* fp, file_header fh){
    fseek(fp, 0x0000, SEEK_SET);
    fwrite(fh.type, 1, 2, fp);
    fwrite(&(fh.size), 12, 1, fp);
}

void read_bitmapinfoHeader(FILE* fp, bitmapinfo_header* bh){
    fseek(fp, 0x000e, SEEK_SET);
    fread(bh, 28, 1, fp);
}

void write_bitmapinfoHeader(FILE* fp, bitmapinfo_header bh){
    fseek(fp, 0x000e, SEEK_SET);
    fwrite(&bh, 28, 1, fp);
}

void read_bitmapAll(FILE* fp, int max_size, file_header fh, bitmapinfo_header bh, rgb_t fig[][max_size]){
    fseek(fp, fh.offset, SEEK_SET);
    for(int y=0; y < bh.y_size; y++){
        for(int x=0; x < bh.x_size; x++){
            fread(&fig[x][y], 3, 1, fp);
        }
        fseek(fp, bh.x_size%4, SEEK_CUR);
    }
}

void write_bitmapAll(FILE* fp, int max_size, file_header fh, bitmapinfo_header bh, rgb_t fig[][max_size]){
    write_fileHeader(fp, fh);
    write_bitmapinfoHeader(fp, bh);
    
    fseek(fp, fh.offset, SEEK_SET);
    for(int y=0; y < bh.y_size; y++){
        for(int x=0; x < bh.x_size; x++){
            fwrite(&fig[x][y], 3, 1, fp);
        }
        fseek(fp, bh.x_size%4, SEEK_CUR);
    }
}

void rotation(int max_size, bitmapinfo_header* bh, rgb_t fig[][max_size], char flag);
int main(int argc, char** argv){
    char filename[64];
    FILE* fp;
    file_header fh = {"", 0, 0};
    bitmapinfo_header bh = {0, 0 ,0, 0, 0, 0, 0, 0};
    int max_size;
    char flag;

    if(argc == 1){
        flag = 0;
    }else if(argc == 2){
        if(strcmp(argv[1], "-left") == 0){
            flag = 1;
        }else if(strcmp(argv[1], "-right") == 0){
            flag = 2;
        }else{
            printf( "Argument Value Error\n" );
        }
    }else{
        printf( "The number of arguments Error\n" );
    }

    printf( "filename ? :" );
    scanf( "%s" , filename);

    fp = fopen(filename, "rb"); //バイナリモード
    if(fp == NULL){
        printf( "Can not open\n" );
        return 1;
    }

    read_fileHeader(fp, &fh);
    read_bitmapinfoHeader(fp, &bh);
    if(!(strcmp(fh.type, "BM")==0 && bh.pixelBit==24 && fh.offset==54)){
        printf( "Different file type.\n" );
        return 1;
    }

    if(bh.x_size > bh.y_size){
        max_size = bh.x_size;
    }else{
        max_size = bh.y_size;
    }

    rgb_t data[max_size][max_size];
    read_bitmapAll(fp, max_size, fh, bh, data);
    fclose(fp);

    rotation(max_size, &bh, data, flag);

    fp = fopen("ex11-2.bmp", "wb"); //バイナリモード
    if(fp == NULL){
        printf( "Can not open\n" );
        return 1;
    }
    write_bitmapAll(fp, max_size, fh, bh, data);
    fclose(fp);
    return 0;
}

void trade(int max_size, bitmapinfo_header* bh, rgb_t fig[][max_size]){
    rgb_t swap;
    for(int y=0; y < (bh->y_size+1)/2; y++){
        for(int x=0; x < bh->x_size; x++){
            swap = fig[x][y];
            fig[x][y] = fig[x][bh->y_size-y-1];
            fig[x][bh->y_size-y-1] = swap;
        }
    }
}

void left(int max_size, bitmapinfo_header* bh, rgb_t fig[][max_size]){
    rgb_t sub[max_size][max_size];
    for(int y=0; y < bh->y_size; y++){
        for(int x=0; x < bh->x_size; x++){
            sub[x][y] = fig[x][y];
        }
    }

    for(int y=0; y < bh->y_size; y++){
        for(int x=0; x < bh->x_size; x++){
            fig[bh->y_size-y-1][x] = sub[x][y];
        }
    }
    
    int swap = bh->x_size;
    bh->x_size = bh->y_size;
    bh->y_size = swap;
}

void right(int max_size, bitmapinfo_header* bh, rgb_t fig[][max_size]){
    rgb_t sub[max_size][max_size];
    for(int y=0; y < bh->y_size; y++){
        for(int x=0; x < bh->x_size; x++){
            sub[x][y] = fig[x][y];
        }
    }

    for(int y=0; y < bh->y_size; y++){
        for(int x=0; x < bh->x_size; x++){
            fig[y][bh->x_size-x-1] = sub[x][y];
        }
    }
    
    int swap = bh->x_size;
    bh->x_size = bh->y_size;
    bh->y_size = swap;
}

void rotation(int max_size, bitmapinfo_header* bh, rgb_t fig[][max_size], char flag){
    switch(flag){
    case 0:
        trade(max_size, bh, fig);
        break;
    case 1:
        left(max_size, bh, fig);
        break;
    case 2:
        right(max_size, bh, fig);
        break;
    }
}