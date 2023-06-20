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

typedef struct {
    double re; // real part（実部）
    double im; // imaginary part（虚部）
} complex_number; 

void print_complex(complex_number cn);
complex_number cmp_add(complex_number cn1, complex_number cn2);
complex_number cmp_sub(complex_number cn1, complex_number cn2);
complex_number cmp_mul(complex_number cn1, complex_number cn2);
int main(void){
    printf( "(3.0 + 4.0j)*(3.0 - 4.0j) - (2.0 + 1.0j) = " );
    complex_number cn1 = {3.0, 4.0};
    complex_number cn2 = {3.0, -4.0};
    complex_number cn3 = {2.0, 1.0};
    print_complex(cmp_sub(cmp_mul(cn1, cn2), cn3));
}

void print_complex(complex_number cn){
    if(cn.im < 0){
        printf( "%.2f - %.2fj\n" , cn.re, -cn.im);
    }else if(cn.im > 0){
        printf( "%.2f + %.2fj\n" , cn.re, cn.im);
    }else{
        printf( "%.2f\n" , cn.re);
    }
}

complex_number cmp_add(complex_number cn1, complex_number cn2){
    complex_number cn = {cn1.re + cn2.re, cn1.im + cn2.im};
    return cn;
}

complex_number cmp_sub(complex_number cn1, complex_number cn2){
    complex_number cn = {cn1.re - cn2.re, cn1.im - cn2.im};
    return cn;
}

complex_number cmp_mul(complex_number cn1, complex_number cn2){
    complex_number cn = {cn1.re * cn2.re - cn1.im * cn2.im, cn1.im * cn2.re + cn1.re * cn2.im};
    return cn;
}