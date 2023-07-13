#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#define PREF_SIZE 20
#define CITY_SIZE 50
#define ADDR_SIZE 100
#define FULL_ADDR_SIZE 170

typedef struct _zipnode {
    int zip;
    char fulladdr[FULL_ADDR_SIZE];
    struct _zipnode *next; // 次のノードのポインタ
} zipnode_t;

int add_node(zipnode_t **head, int zip, char *fulladdr){
    zipnode_t* node = *head;
    *head = malloc(sizeof(zipnode_t));
    (*head)->zip = zip;
    strcpy((*head)->fulladdr, fulladdr);
    (*head)->next = node;
    return 0;
}

zipnode_t* search_node(zipnode_t *head, char *fulladdr){
    while(head != NULL){
        if(strcmp(head->fulladdr, fulladdr) == 0){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int print_n_node(zipnode_t *head, int n){
    int i = 0;
    while(head != NULL && i < n){
        printf( "%d : %s\n" , head->zip, head->fulladdr);
        head = head->next;
        i++;
    }
    return i;
}

void free_node(zipnode_t *head){
    while(head != NULL){
        zipnode_t* node = head->next;
        free(head);
        head = node;
    }
}

int read_from_csv(zipnode_t **head, FILE *infp){  // return the number of data
	int chofs, zip, n=0;
	char instr[BUF_SIZE];
	char zip_char[ZIPCHAR_SIZE];
	char pref[PREF_SIZE];
	char city[CITY_SIZE];
	char addr[ADDR_SIZE];
    char fulladdr[FULL_ADDR_SIZE];

	while (fgets(instr, BUF_SIZE, infp) != NULL) {
		chofs = 0;
		chofs = csv_dq_read(instr, zip_char, '"', chofs);
		zip = atoi(zip_char);
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, pref, '"', chofs);
		strcpy(fulladdr, pref);
        strcat(fulladdr, " ");
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, city, '"', chofs);
		strcat(fulladdr, city);
        strcat(fulladdr, " ");
		chofs = skip_delim(instr, ',', chofs);
		chofs = csv_dq_read(instr, addr, '"', chofs);
		strcat(fulladdr, addr);
        add_node(head, zip, fulladdr);
		n++;
	}
	return n;
}

int main(){
    zipnode_t* head = NULL;

	FILE *infp;
	int	n;
	char key[FULL_ADDR_SIZE];

	if ( ( infp = fopen("tokyo_all_dat.txt", "r")) == NULL) {
		fprintf(stderr, "File not found\n");
		exit(EXIT_FAILURE);
	}
/* ---------------------------------- */
/*    read csv file                   */
/* ---------------------------------- */
	n = read_from_csv(&head, infp);
	printf("number of data = %d\n", n);
	fclose(infp);

    while(1){
        printf( "full address ? > " );
        fgets(key, sizeof(key), stdin);
        key[strlen(key)-1] = '\0';
        if(strcmp(key, "exit")){
            zipnode_t* result = search_node(head, key);
            if(result != NULL){
                printf( "zipcode = %d\n" , result->zip);
            }else{
                printf( "no data\n" );
            }
        }else{
            printf( "Bye!\n" );
            break;
        }
    }
	free_node(head);
    return 0;
}