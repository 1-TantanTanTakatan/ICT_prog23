#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

/* ---------------------------------- */

int skip_delim(char instr[], char delim, int choffset) {
	// printf("skip_delim : offset %d, str %s\n", choffset, &instr[choffset]);
	if (instr[choffset]==delim) {
		choffset++;
	} else {
		fprintf(stderr, "Error at csv_read. Delim Char not found.\n");
	   	exit(-1);
	}
	return (choffset);
}

int csv_dq_read(char instr[], char outstr[], int quote_ch, int choffset) {
	int instr_pos, outstr_pos;

	instr_pos = choffset;
	outstr_pos = 0;
	// printf("csv_dq_read : offset %d, str %s\n", choffset, &instr[choffset]);
    if (instr[instr_pos] == quote_ch) {
    	instr_pos++;
    } else {
    	fprintf(stderr, "Error at csv_read. Quote Char not found.\n");
	   	exit(-1);
    }
	while (instr[instr_pos]!=quote_ch) {
 		if (!isprint(instr[instr_pos])) {
			fprintf(stderr, "Error at csv_read. Wrong char.\n");
		   	exit(-1);
		} else {
			outstr[outstr_pos]=instr[instr_pos];
			outstr_pos++;
		}
		instr_pos++;
	}
	outstr[outstr_pos]=0; // outstr_pos++;
	if (instr[instr_pos]==quote_ch)	/* skip quote char */
		instr_pos++;
	return (instr_pos);
}

/* ---------------------------------- */

#define BUF_SIZE	255
#define ZIPCHAR_SIZE	8
#define PREF_SIZE	20
#define CITY_SIZE	50
#define ADDR_SIZE	100
#define ADDR_ALL_SIZE	255

#define ZIPTABLE_MAX	4000

typedef struct _ziptable {
	int zip;
	char pref[PREF_SIZE];
	char city[CITY_SIZE];
	char addr[ADDR_SIZE];
} ziptable_t;

int read_from_csv(ziptable_t **ziptable, FILE *infp){  // return the number of data
	int chofs, zip, n=0;
	char instr[BUF_SIZE];
	char zip_char[ZIPCHAR_SIZE];
	char pref[PREF_SIZE];
	char city[CITY_SIZE];
	char addr[ADDR_SIZE];

	while (fgets(instr, BUF_SIZE, infp) != NULL) {
        ziptable_t* zt = malloc(sizeof(ziptable_t));

		chofs = 0;
		chofs = csv_dq_read(instr, zip_char, '"', chofs);
		zip = atoi(zip_char);
		zt->zip = zip;
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, pref, '"', chofs);
		strcpy(zt->pref, pref);
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, city, '"', chofs);
		strcpy(zt->city, city);
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, addr, '"', chofs);
		strcpy(zt->addr, addr);
        ziptable[n] = zt;
		n++;
	}
	return n;
}

ziptable_t* linearSearch(ziptable_t* data[], int key, int num){
    for (int i=0; i < num; i++){
        if(data[i]->zip == key){
            return data[i];
        }
    }
    return NULL;
}

void print_ziptable(ziptable_t *ziptable){
    if(ziptable != NULL){
        printf( "%s, %s, %s\n" , ziptable->pref, ziptable->city, ziptable->addr);
    }else{
        printf( "Not Found\n" );
    }
}

int main(){
    ziptable_t* ziptable[ZIPTABLE_MAX];

	FILE *infp;
	int	n;
	int key;

	if ( ( infp = fopen("tokyo_all_dat.txt", "r")) == NULL) {
		fprintf(stderr, "File not found\n");
		exit(EXIT_FAILURE);
	}
/* ---------------------------------- */
/*    read csv file                   */
/* ---------------------------------- */
	n = read_from_csv(ziptable,infp);
	printf("number of data = %d\n", n);
	fclose(infp);

    //printf( "Byte size of Array: %d\n" , sizeof(ziptable));

    while(1){
        scanf( "%d" , &key);
        if(key < 1000000){
            break;
        }else{
            printf( "%d: " , key);
            print_ziptable(linearSearch(ziptable, key, n));
        }
    }
}