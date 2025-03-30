__global__ void vector_dot_product(int *day, float *price, float *c) {
    __shared__ float temp[7];
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    for (int j = 0; j < 4; j++) {
        temp[i] += day[j][i] * price[j];
    }
}
int main() {
    int[4][7] day = {
        {3, 13, 16, 5},
        {5, 22, 17, 37},
        {2, 22, 17, 37},
        {0, 22, 17, 37}
    };
    float[4] price = {29.99, 14.99, 9.99, 24.99};
    float[7] c;
    dim3 block(1, 1, 1);
    dim3 grid(7, 1, 1);

    float *d_day, *d_price, *d_c;
    // Allocate memory on the GPU
    cudaMalloc((void**)&d_day, 7 * 4 * sizeof(int));
    cudaMalloc((void**)&d_price, 4 * sizeof(float));
    cudaMalloc((void**)&d_c, 7 * sizeof(float));
    // Copy the input vectors from host memory to GPU buffers
    cudaMemcpy(d_day, day, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_price, price, size, cudaMemcpyHostToDevice);
    // Launch the vector_add kernel on GPU
    vector_dot_product<<<grid, block>>>(d_day, d_price, d_c);
    // Copy the result vector from GPU buffer to host memory
    cudaMemcpy(c, d_c, sizeof(float), cudaMemcpyDeviceToHost);
    // Free GPU memory
    cudaFree(d_day);
    cudaFree(d_price);
    cudaFree(d_c);
    // Print the result
    for (int i = 0; i < 7; i++) {
        printf("Sales for [%d]: %f\n", i, c[i]);
    }

    return 0;
}