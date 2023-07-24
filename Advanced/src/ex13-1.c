#include <stdio.h>

int main(void){
    char str[128];
    int num = 0;
    scanf( "%s" , str);

    int i = 0;
    while(str[i] != '\0'){
        num *= 10;
        num += str[i] - '0';
        i++;
    }

    printf( "%d\n" , num);
    return 0;
}