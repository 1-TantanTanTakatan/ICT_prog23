/*
 ============================================================================
 Name        : ex3-2-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#define N_PERSON 50 /* #person */

struct pdata_st {
    char name[40];
    int gender;
    char address[100];
};

struct pdata_st pdata[N_PERSON] = {
    {"Taro", 1, "Ookayama, Meguro-ku, Tokyo, JAPAN"},
    {"Hanako", 2, "Suzukakedai, Midori-ku, Yokohama, JAPAN"},
    {"Jiro", 1, "Tamachi, Minato-ku, Tokyo, JAPAN"},
    {"Ichiro", 1, "Miami, Florida, USA"},
    {"Naomi", 2, "Palm Beach, Florida, USA"}};

void printPdata(struct pdata_st* ps);
struct pdata_st* linearSearch(struct pdata_st data[], char* key);
int main(void){
    char name[40];
    scanf( "%s" , name);
    printPdata(linearSearch(pdata, name));
}

void printPdata(struct pdata_st* ps){
    if(ps == NULL){
        printf( "Not Found\n");
    }else{
        printf( "Gender: %d, Address: %s\n" , ps->gender, ps->address);
    }
}

struct pdata_st* linearSearch(struct pdata_st data[], char* key){
    for (int i=0; i < N_PERSON; i++){
        if (strcmp(data[i].name, key) == 0){
            return &data[i];
        }
    }
    return NULL;
}