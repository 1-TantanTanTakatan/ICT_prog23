#include <stdio.h>
#include <string.h>
#include "ex12-2.h"

int main(void){
    printf( "(3.0 + 4.0j)*(3.0 - 4.0j) - (2.0 + 1.0j) = " );
    complex_number cn1 = {3.0, 4.0};
    complex_number cn2 = {3.0, -4.0};
    complex_number cn3 = {2.0, 1.0};
    print_complex(cmp_sub(cmp_mul(cn1, cn2), cn3));
}