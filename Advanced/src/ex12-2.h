typedef struct {
    double re; // real part（実部）
    double im; // imaginary part（虚部）
} complex_number;

void print_complex(complex_number cn);
complex_number cmp_add(complex_number cn1, complex_number cn2);
complex_number cmp_sub(complex_number cn1, complex_number cn2);
complex_number cmp_mul(complex_number cn1, complex_number cn2);