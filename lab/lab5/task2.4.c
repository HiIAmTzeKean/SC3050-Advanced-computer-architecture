__global__ void vector_dot_product(int *day, float *price, float *c) {
    __shared__ float temp[7];
    __shared__ float price_temp[4];
    // Copy the price array to shared memory
    if (threadIdx.x < 4) {
        price_temp[threadIdx.x] = price[threadIdx.x];
    }
    __syncthreads(); // Synchronize threads within a block

    int i = blockIdx.x * blockDim.x + threadIdx.x;
    for (int j = 0; j < 4; j++) {
        temp[i] += day[j][i] * price_temp[j];
    }
}
int main() {
    int day[4][7] = {
        {3, 2, 0, 3, 4, 10, 8},
        {5, 4, 3, 5, 5, 13, 11},
        {2, 5, 3, 4, 5, 21, 15},
        {0, 1, 1, 4, 3, 16, 8}
    };
    float price[4] = {29.99, 14.99, 9.99, 24.99};
    float c[7];
    float *d_day, *d_price, *d_c;
    // Allocate memory on the GPU
    cudaMalloc((void**)&d_day, 7 * 4 * sizeof(int));
    cudaMalloc((void**)&d_price, 4 * sizeof(float));
    cudaMalloc((void**)&d_c, 7 * sizeof(float));
    // Copy the input vectors from host memory to GPU buffers
    cudaMemcpy(d_day, day, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_price, price, size, cudaMemcpyHostToDevice);
    // Launch the vector_add kernel on GPU
    vector_dot_product<<<1, 7>>>(d_day, d_price, d_c);
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