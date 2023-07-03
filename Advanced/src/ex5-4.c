#include<stdio.h>

void vec_mult_s(int n, float *in, float a, float *out){
    for(int i=0; i < n; i++){
        out[i] = in[i] * a;
    }
}

int vec_div(int n, float *in, float a, float *out){
    if(a){
        for(int i=0; i < n; i++){
            out[i] = in[i] / a;
        }
        return 0;
    }else{
        return -1;
    }
}

void vec_sub(int n, float *in1, float *in2, float *out){
    for(int i=0; i < n; i++){
        out[i] = in1[i] - in2[i];
    }
}

void vec_swap(int n, float *in1, float *in2){
    for(int i=0; i < n; i++){
        int temp = in1[i];
        in1[i] = in2[i];
        in2[i] = temp;
    }
}

int mat_inv(int n, float in[n][n], float out[n][n]){
    float temp[n];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(i==j){
                out[i][j] = 1;
            }else{
                out[i][j] = 0;
            }
        }
    }

    for(int i=0; i < n; i++){
        if(in[i][i]==0){
            for(int j=i+1; j < n; j++){
                if(in[j][j]){
                    vec_swap(n, in[i], in[j]);
                    vec_swap(n, out[i], out[j]);
                    break;
                }
            }
        }

        float k = in[i][i];
        if(vec_div(n, in[i], k, in[i])){
            return -1;
        }else{
            vec_div(n, out[i], k, out[i]);
            for(int j=0; j < n; j++){
                if(i != j){
                    k = in[j][i];
                    vec_mult_s(n, in[i], k, temp);
                    vec_sub(n, in[j], temp, in[j]);
                    vec_mult_s(n, out[i], k, temp);
                    vec_sub(n, out[j], temp, out[j]);
                }
            }
        }
    }
    return 0;
}

void print_matrix(int n, float mat[][n]){
    for(int i=0; i < n; i++){
        printf( "%.2f" , mat[i][0]);
        for(int j=1; j < n; j++){
            printf( " %.2f" , mat[i][j]);
        }
        printf( "\n" );
    }
}

int main(){
    int n;
    
    FILE* fp = fopen("matrix.txt", "r");
    fscanf(fp, "%d" , &n);
    float mat[n][n], mat2[n][n];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            fscanf(fp, "%f" , &mat[i][j]);
        }
    }
    fclose(fp);

    printf( "Input Matrix:\n" );
    print_matrix(n, mat);
    if(mat_inv(n, mat, mat2)){
        printf( "Not invertible\n" );
    }else{
        printf( "Inverse of Matrix:\n" );
        print_matrix(n, mat2);
    }

    return 0;
}