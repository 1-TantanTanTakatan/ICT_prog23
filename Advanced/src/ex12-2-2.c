#include <stdio.h>
#include <string.h>
#include "ex12-2.h"

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