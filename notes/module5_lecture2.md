# Cache replacement

## Replacement policy

Should respect these principles

- Principle of locality
- Principle of temporal

Some possible policies are

- FIFO
- LRU
  - Needs to factor in temporal locality which slows down the system
- Not most recently used
- Random

Depends on associativity

- $a <= 2$, LRU cheap
- $a > 2$, harder cost

## Write policy

- Memory hierarchy
  - Performs as fast as cache
  - As large as the storage

Some write policies

- Write through
  - Write to entire hierarchy which is slow since there is high bandwidth needed
  - Write updates L1,L2
  - Beyond L2 use write back
- Write back (Castout)
  - Write to top level only
  - Maintain state of cache with some bits
  - Only update when we evict, this allows for bulk update once rather than to
    update for each update to the line

Complication of write back

- Multi-core system
  - Each core have their own cache which could cause issue when the lower level
    not updated
  - This is called **cache coherence** problem
- DMA issues
  - devices that use DMA might also access stale memory which we must be careful

## Instruction and data cache

- Data stores data only
- Instruction stores instruction
- We want to use spacial locality
- Harvard architecture gives a lot of advantage
- Hybrid archi, Harvard on L1 cache, Von Neuman on lower level

## Examples

- For a memory of 64 bits, we need 6 bits.
- If the block size if 4, we need 2 bits in offset (o)
- S = 4 (i)
- E = 2, two way set associative (not always equal to t)
- Cache blocks = E * S = 8 blocks

## Question to clarify

- what is associativity and how to calculate it
- Find out more on the hybrid and why we still use von neuman for lower level