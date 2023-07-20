#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUF_SIZE 1000

int main(void){
    char instr[BUF_SIZE];
    FILE* infp = fopen("ex9_0_plain.txt", "r");
    FILE* outfp = fopen("ex9-0-cipher.txt", "w");

    while (fgets(instr, BUF_SIZE, infp) != NULL){
        instr[strlen(instr)] = '\0';
        int length = strlen(instr);
        for(int i=0; i < length; i++){
            if(instr[i]>='A' && instr[i]<='Z'){
                instr[i] = (instr[i] - 'A' + 3) % 26 + 'A';
            }
        }
        fputs(instr, outfp);
    }
    fclose(infp);
    fclose(outfp);
    return 0;
}