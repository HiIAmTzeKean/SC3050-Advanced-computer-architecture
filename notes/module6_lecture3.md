# GPU internal operation

## GPU hardware perspective

CUDA allows us to view from a software level. CUDA runtime system will allocate
the hardware. SM -> SP/CUDA core.

Kernel launch will cause each SP core to execute one thread.

### SM block allocation

Thread block can be scheduled on any SM, but blocks cannot split across SM.

Balance between

- SM utilisation -> 1 block per SM
- Thread to block allocation -> to have 1 block with all threads or multiple

## Hardware utilisation
