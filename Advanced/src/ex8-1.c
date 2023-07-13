#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 128

enum gender {Male, Female};

typedef struct personal_st {
    char name[20];
    enum gender gender;
    int age;
} personal_t;

unsigned int hash(char *str) {
    int hashval = 0;
    while (*str != '\0') {
    hashval = hashval + *str;
    str++;
    }
    return (hashval % SIZE);
}

int setup_hashTable(personal_t* table[]){
    char buff[26];
    FILE* fp;

    for(int i=0; i < SIZE; i++){
        table[i] = NULL;
    }
    
    if ( ( fp = fopen("personal_data.txt", "r")) == NULL) {
		fprintf(stderr, "File not found\n");
		exit(EXIT_FAILURE);
	}

    while (fgets(buff, sizeof(buff), fp) != NULL){
        char name[20];
        int gender;
        int age;

        int n = sscanf(buff, "%s %d %d", name, &gender, &age);
        if (n != 3) {
            printf("Input error/n");
            return 1;
        }

        int i = hash(name);
        if(table[i]==NULL){
            table[i] = malloc(sizeof(personal_t));
            strcpy(table[i]->name, name);
            table[i]->gender = gender - 1;
            table[i]->age = age;
        }else{
            printf( "collision\n" );
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

personal_t* search_hashTable(personal_t* table[], char* key){
    return table[hash(key)];
}

char* gender_to_string(enum gender g){
    switch (g){
    case Male:
        return "Male";
    
    case Female:
        return "Female";

    default:
        return "Other";
    }
}

void print_personal(personal_t* pt){
    printf( "( %s %s %d )\n\n" , pt->name, gender_to_string(pt->gender), pt->age);
}

void free_hashTable(personal_t* table[]){
    for(int i=0; i < SIZE; i++){
        if(table[i]!=NULL){
            free(table[i]);
        }
    }
}

int main(){
    personal_t* table[SIZE];
    char key[20];
    
    if(setup_hashTable(table)){
        return 1;
    }else{
        while(1){
            printf( "Name ? > " );
            fgets(key, sizeof(key), stdin);
            key[strlen(key)-1] = '\0';
            if(strcmp(key, "exit")){
                personal_t* result = search_hashTable(table, key);
                if(result != NULL){
                    print_personal(result);
                }else{
                    printf( "no data\n" );
                }
            }else{
                printf( "Bye!\n" );
                break;
            }
        }
    }
    free_hashTable(table);
    return 0;
}