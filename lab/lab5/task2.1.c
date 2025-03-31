__global__ void cuda_hello(int n) {
    printf("Hello from GPU%d[%d]!\n",
           n, threadIdx.x);
}

int main() {
    printf("Hello from CPU!\n");
    cuda_hello<<<1,4>>>(1);
    cudaDeviceSynchronize();
    cuda_hello<<<1,6>>>(2);
    return 0;
}