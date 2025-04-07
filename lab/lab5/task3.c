#include <stdio.h>
#include <cuda_runtime.h>

__global__ void calculator(int *day, float *price, float *c) {
    __shared__ float temp[7];
    __shared__ float price_temp[4];
    if (threadIdx.x < 4) {
        price_temp[threadIdx.x] = price[threadIdx.x];
    }
    __syncthreads();

    int i = blockIdx.x * blockDim.x + threadIdx.x;
    for (int j = 0; j < 4; j++) {
        temp[i] += day[j*7 + i] * price_temp[j];
    }
    c[i] = temp[i];
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
    int *d_day;
    float *d_price, *d_c;
    // Allocate memory on the GPU
    cudaMalloc((void**)&d_day, 7 * 4 * sizeof(int));
    cudaMalloc((void**)&d_price, 4 * sizeof(float));
    cudaMalloc((void**)&d_c, 7 * sizeof(float));
    cudaMemcpy(d_day, day, 7 * 4 * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_price, price, 4 * sizeof(float), cudaMemcpyHostToDevice);
    vector_dot_product<<<1, 7>>>(d_day, d_price, d_c);
    cudaDeviceSynchronize();

    cudaMemcpy(c, d_c, 7 * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(d_day);
    cudaFree(d_price);
    cudaFree(d_c);
    
    for (int i = 0; i < 7; i++) {
        printf("Sales for [%d]: %f\n", i, c[i]);
    }

    return 0;
}