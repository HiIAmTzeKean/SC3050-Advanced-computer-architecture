__global__ void vector_dot_product(int *a, int *b, int *c) {
    __shared__ int temp[4];
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    temp[i] = a[i] * b[i];
    __syncthreads(); // Synchronize threads within a block
    if (i == 0) {
        int sum = 0;
        for (int j = 0; j < blockDim.x; j++) {
            sum += temp[j];
        }
        *c = sum; // Store the result in c
    }
}

int main() {
    int[4] a = {22, 13, 16, 5};
    int[4] b = {5, 22, 17, 37};
    int c;
    int *d_a, *d_b, *d_c;
    int size = 4 * sizeof(int);
    // Allocate memory on the GPU
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, sizeof(int));
    // Copy the input vectors from host memory to GPU buffers
    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);
    // Launch the vector_add kernel on GPU
    vector_dot_product<<<1, 4>>>(d_a, d_b, d_c);
    // Copy the result vector from GPU buffer to host memory
    cudaMemcpy(c, d_c, sizeof(int), cudaMemcpyDeviceToHost);
    // Free GPU memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    // Print the result
    printf("Dot product: %d\n", c);
    return 0;
}