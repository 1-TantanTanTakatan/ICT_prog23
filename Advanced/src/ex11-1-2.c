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

void read_bitmapinfoHeader(FILE* fp, bitmapinfo_header* bh){
    fseek(fp, 0x000e, SEEK_SET);
    fread(bh, 28, 1, fp);
}

rgb_t read_bitmap(FILE* fp, int x, int y, file_header fh, bitmapinfo_header bh){
    rgb_t rgb;
    fseek(fp, fh.offset+y*(3*bh.x_size+bh.x_size%4)+3*x, SEEK_SET);
    fread(&rgb, 3, 1, fp);
    return rgb;
}

int main(void){
    char filename[64];
    file_header fh = {"", 0, 0};
    bitmapinfo_header bh = {0, 0 ,0, 0, 0, 0, 0, 0};
    rgb_t data;

    printf( "filename ? :" );
    scanf( "%s" , filename);

    FILE* fp = fopen(filename, "rb"); //バイナリモード
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

    printf( "Horizontal size = %d, Vertical size = %d,\n" , bh.x_size, bh.y_size);
    data = read_bitmap(fp, 0, bh.y_size-1, fh, bh);
    printf( "Upper-left (R=%d, G=%d, B=%d)\n" , data.r, data.g, data.b);
    data = read_bitmap(fp, bh.x_size-1, bh.y_size-1, fh, bh);
    printf( "Upper-right (R=%d, G=%d, B=%d)\n" , data.r, data.g, data.b);
    data = read_bitmap(fp, 0, 0, fh, bh);
    printf( "Lower-left (R=%d, G=%d, B=%d)\n" , data.r, data.g, data.b);
    data = read_bitmap(fp, bh.x_size-1, 0, fh, bh);
    printf( "Lower-right (R=%d, G=%d, B=%d)\n" , data.r, data.g, data.b);
    return 0;
}