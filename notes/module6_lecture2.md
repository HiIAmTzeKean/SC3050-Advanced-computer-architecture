# GPU internal

## Nvidia GPU

- Data parallel computation dealing with math
- Simple logic but huge volume

## Architecture

32 compute units known as CUDA cores per SM.

- ALU and FPU
- Load/store unit
- Special function unit for transcendental instr. (sin, cos)
- Shared memory and cache

Later introduced clusters that contain SM which in turn contain CUDA core. Tensor
core later added as well for matrix operation.

## CUDA Programming

Problem decomposed into sub problems, each allocated to a **thread block**.
Each block general multi threads to work.

CUDA consist of host (CPU) and device (GPU). Program will start from host which
launch parallel threads which are executed on the device.

CUDA is a C program extension, the file will be stored as `.cu` instead. Compiled
with `nvcc`.

`__global__` added to the declaration to specify GPU run. Looks like a function
call, we call the function in the main program `hello_GPPU<<<1,1>>>()` which the
device code will launch as a kernel in CUDA.

### Compilation

Device code compiled by nvcc while host code compiles on `gcc`.

Kernel is a C function executed by GPU in parallel. The 2 parameter defined specifies
the (1) number of thread blocks and (2) number of threads in each block. This
is known as the execution configuration syntax.

### Thread blocks

Each thread has a unique thread ID, call `threadIdx.x` to obtain. The block would
be `blockIdx.x`. The `blockDim` determines the number of thread per block.

```c
int i = blockIdx.x * blockDim.x + threadIdx.x
```

Determines the global position of the thread.

### Share memory

```__shared__```

### Sync thread

```__syncthreads()```
