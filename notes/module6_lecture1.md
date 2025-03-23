# GPU Architecture

## Motivation GPU

Acceleration for graphics and mathematical computing

- 3D games
- AI application

CNN a deep learning algorithm benefited particularly from GPU compute

- Discrete compute acceleration
- Multiplication and Accumulation (MAC) operation
- pixel vector multiplied with factor vector

Convolution in CNN

- We have input and filter and we apply filter over input to get output
- MAC operation are independent
- That means we can do parallel compute without issues

Recall that CPU designed with features like data forwarding etc due to data
dependence issues which do not benefit from MAC operations.

-> We want simple instructions that can perform parallel operations without
complex need to handle data dependency. Single data multiple instruction (SIMD)
accelerates this!

## Evolution

SIMD allows us to do parallel operation.

- Vector processor
- Array processor
- GPU

## CPU in relation

CPU designed for single threaded code -> sequential code -> low latency to execute
it fast with data dependencies. CPU enhanced with many logical circuits such as
superscalar and pipelining.

Adding more cores allows us to execute in parallel. We aim to run concurrent code
such as OpenMP rather than just sequential code.

To support SIMD, ALU has been duplicated to allow same instruction to execute
simultaneously. This is costly and power expensive.

### Fixed function pipeline

- Configurable, not programmable

### Programmable graphics pipeline

- Certain functions in pipeline can vary

### Unified GPU architecture

- Instead of having separate processors, use the same processor core
- Use a single processor (unified) rather than having many mini processor
- Closer to CPU design, we create a single processor that can perform different
  function
- Focus on adding ALU to each block and independent blocks of ALU

## GPU saves the day

GPU contains many cores (Streaming multi-processor, Compute unit) which
contain many ALU. Each core contains streaming processors that perform the compute.

## Programming on CUDA

Require programs such as OpenGL to use the GPU via API. GPU resembles super parallel
computers.

### General purpose Computing GPU

Casting problem into a GPU

### CUDA programming

- Compute Unified Device Architecture
- API for direct access to internal processing unit for parallel programming
- OpenCL
  - Parallel program for not only GPU
  - But also CPU etc
- This is known as GPU computing

## Question to clarify
