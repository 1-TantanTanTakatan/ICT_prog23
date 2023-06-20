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

struct address_st {
    char address[100]; /* Detailed Address */
    char zip[10]; /* Postal Code */
    char country[20]; /* Country/Region */
};

struct pdata2_st {
    char name[40]; /* Name */
    int gender; /* Gender(1=Male, 2=Female) */
    struct address_st addr; /* Address */
};

struct pdata2_st pdata2[N_PERSON] = {
    {"Taro", 1, {"Ookayama, Meguro-ku, Tokyo", "", "Japan"}},
    {"Hanako", 2, {"Suzukakedai, Midori-ku, Yokohama", "", "Japan"}},
    {"Jiro", 1, {"Tamachi, Minato-ku, Tokyo", "", "Japan"}},
    {"Ichiro", 1, {"Miami, Florida", "", "USA"}},
    {"Naomi", 2, {"Palm Beach, Florida", "", "USA"}}};

void printPdata2(struct pdata2_st* ps);
struct pdata2_st* linearSearch(struct pdata2_st data[], char* key);
int main(void){
    char name[40];
    scanf( "%s" , name);
    printPdata2(linearSearch(pdata2, name));
}

void printPdata2(struct pdata2_st* ps){
    if(ps == NULL){
        printf( "Not Found\n");
    }else{
        printf( "Gender: %d, Address: %s, Country: %s\n" , ps->gender, ps->addr.address, ps->addr.country);
    }
}

struct pdata2_st* linearSearch(struct pdata2_st data[], char* key){
    for (int i=0; i < N_PERSON; i++){
        if (strcmp(data[i].name, key) == 0){
            return &data[i];
        }
    }
    return NULL;
}