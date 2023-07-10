#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node_st{
    char fullname[30];
    struct node_st *next; 
} node_t;

int add_node(node_t **head, char *str){
    node_t* node = *head;
    *head = malloc(sizeof(node_t));
    strcpy((*head)->fullname, str);
    (*head)->next = node;
    return 0;
}

void print_node(node_t *head){
    while(head != NULL){
        printf( "%s\n" , head->fullname);
        head = head->next;
    }
}

void free_node(node_t *head){
    while(head != NULL){
        node_t* node = head->next;
        free(head);
        head = node;
    }
}

int main(){
    node_t* head = NULL;
    for(int i=0; i < 3; i++){
        char fullname[30];
        printf( "full name? " );
        fgets(fullname, sizeof(fullname), stdin);
        fullname[strlen(fullname)-1] = '\0';
        add_node(&head, fullname);
    }
    printf( "----------------------\n" );
    print_node(head);

    free_node(head);
    return 0;
}