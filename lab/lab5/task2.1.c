__global__ void cuda_hello(){
    printf("Hello from GPU%d[%d]!\n",
           blockIdx.x, threadIdx.x);
}

int main() {
    printf("Hello from CPU!\n");
    cuda_hello<<<1,4>>>();
    cuda_hello<<<1,6>>>();
    return 0;
}