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

#define ZIPTABLE_MAX	10000

typedef struct _ziptable {
	int zip;
	char pref[PREF_SIZE];
	char city[CITY_SIZE];
	char addr[ADDR_SIZE];
} ziptable_t;

int read_from_csv(ziptable_t *ziptable, FILE *infp){  // return the number of data
	int chofs, zip, n=0;
	char instr[BUF_SIZE];
	char zip_char[ZIPCHAR_SIZE];
	char pref[PREF_SIZE];
	char city[CITY_SIZE];
	char addr[ADDR_SIZE];

	while (fgets(instr, BUF_SIZE, infp) != NULL) {
		chofs = 0;
		chofs = csv_dq_read(instr, zip_char, '"', chofs);
		zip = atoi(zip_char);
		ziptable[n].zip = zip;
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, pref, '"', chofs);
		strcpy(ziptable[n].pref, pref);
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, city, '"', chofs);
		strcpy(ziptable[n].city, city);
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, addr, '"', chofs);
		strcpy(ziptable[n].addr, addr);
		n++;
	}
	return n;
}

int main(void) {
	ziptable_t ziptable[ZIPTABLE_MAX];

	FILE *infp;
	clock_t start, end;
	int	k, n;
	int key, pos;

	if ( ( infp = fopen("test_dat.txt", "r")) == NULL) {
		fprintf(stderr, "File not found\n");
		exit(EXIT_FAILURE);
	}
/* ---------------------------------- */
/*    read csv file                   */
/* ---------------------------------- */
	n = read_from_csv(ziptable,infp);
	printf("number of data = %d\n", n);
	fclose(infp);
	/* この後を適切に作成して下さい */
}
