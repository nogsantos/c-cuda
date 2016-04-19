#include <stdio.h>

int main() {
    int dimx = 10;
    int num_bytes = dimx * sizeof (int);
    
    // device and host pointers
    int *d_a = 0;
    int *h_a = 0; 
    /*Aloca memória na CPU para n inteiros*/
    h_a = (int*) malloc(num_bytes);
    printf("%i\n", num_bytes);
    /*Aloca memória na GPU para n inteiros*/
    cudaMalloc(&d_a, num_bytes);

    if (0 == h_a || 0 == d_a) {
        printf("couldn't allocate memory\n");
        return 1;
    }

    cudaMemset(d_a, 0, num_bytes);
    cudaMemcpy(h_a, d_a, num_bytes, cudaMemcpyDeviceToHost);

    
    for (int i = 0; i < dimx; i++){
        printf("%d ", i+1);
    }
    printf("\n");

    free(h_a);
    cudaFree(d_a);
    
    return 0;
    
}