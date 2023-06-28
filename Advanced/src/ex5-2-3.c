#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

typedef struct{
    char name[30];
    int age;
    int gender;
} person_t;

void swap_univ(void* a, void* b, int size){
    char* A = (char*) a;
    char* B = (char*) b;

    for(int i=0; i < size; i++) {
        char temp = *(A+i);
        *(A+i) = *(B+i);
        *(B+i) = temp;
    }
};

int main(){
    person_t p1 = {"Alice", 20, 1};
    person_t p2 = {"Bob", 30, 2};
    int one=1;
    int zero=0;
    printf( "p1:Name=%s, Age=%d, Gender=%d, p2:Name=%s, Age=%d, Gender=%d, zero=%d, one=%d\n" , p1.name, p1.age, p1.gender, p2.name, p2.age, p2.gender, zero, one);
    swap_univ(&p1, &p2, sizeof(p1)); // p1とp2のデータを入れ替える
    swap_univ(&zero, &one, sizeof(zero)); // oneとzeroの値を入れ替える
    printf( "p1:Name=%s, Age=%d, Gender=%d, p2:Name=%s, Age=%d, Gender=%d, zero=%d, one=%d\n" , p1.name, p1.age, p1.gender, p2.name, p2.age, p2.gender, zero, one);
    return 0;
}