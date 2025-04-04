__global__ void vector_add(int *a, int *b, int *c) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    c[i] = a[i] + b[i];
    
}

int main() {
    int[4] a = {22, 13, 16, 5};
    int[4] b = {5, 22, 17, 37};
    int[4] c;
    int *d_a, *d_b, *d_c;
    int size = 4 * sizeof(int);
    // Allocate memory on the GPU
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);
    // Copy the input vectors from host memory to GPU buffers
    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);
    // Launch the vector_add kernel on GPU
    vector_add<<<1, 4>>>(d_a, d_b, d_c);
    // Copy the result vector from GPU buffer to host memory
    cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);
    // Free GPU memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    // Print the result
    for (int i = 0; i < 4; i++) {
        printf("%d + %d = %d\n", a[i], b[i], c[i]);
    }
    return 0;
}