#include <stdio.h>
#include <cuda_runtime.h>

__global__ void calculator_shared_mem(int *day, float *price, float *c) {
    __shared__ float result[7];
    __shared__ float price_temp[4];
    // Copy data from global memory to shared memory
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (threadIdx.x < 4) {
        price_temp[threadIdx.x] = price[threadIdx.x];
    }
    __syncthreads();

    result[i] = 0;
    for (int j = 0; j < 4; j++) {
        result[i] += day[j*7 + i] * price_temp[j];
    }
    c[i] = result[i];
}

__global__ void calculator_global_mem(int *day, float *price, float *c) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    c[i] = 0;
    for (int j = 0; j < 4; j++) {
        c[i] += day[j*7 + i] * price[j];
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
    int *d_day;
    float *d_price, *d_c;

    cudaMalloc((void**)&d_day, 7 * 4 * sizeof(int));
    cudaMalloc((void**)&d_price, 4 * sizeof(float));
    cudaMalloc((void**)&d_c, 7 * sizeof(float));
    cudaMemcpy(d_day, day, 7 * 4 * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_price, price, 4 * sizeof(float), cudaMemcpyHostToDevice);
    
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // Record the start event
    cudaEventRecord(start, 0);
    calculator_shared_mem<<<1, 7>>>(d_day, d_price, d_c);
    cudaDeviceSynchronize();

    // Record the stop event
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    // Calculate elapsed time
    float elapsedTime;
    cudaEventElapsedTime(&elapsedTime, start, stop);
    printf("Kernel execution time: %f ms\n", elapsedTime);

    // Cleanup CUDA events
    cudaEventDestroy(start);
    cudaEventDestroy(stop);

    cudaMemcpy(c, d_c, 7 * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(d_day);
    cudaFree(d_price);
    cudaFree(d_c);
    
    for (int i = 0; i < 7; i++) {
        printf("Sales for [%d]: %f\n", i, c[i]);
    }

    return 0;
}