# Cache design

Memory to store data. There are various types of memory. Cache is small in size,
this brings some issues

- placement of bits in memory (storage location)
- identification of bits needed (find fast)
- replacement of memory when full (during block miss)
- write policy to propagate change (fast update)

## Design principles

L1 cache, L2 cache and higher levels. Generally the higher the level, the slower
the cache.

Cache is not addressed by addr but by content, Content Addressable Memory (CAM).

- We need to check the contents of cache to find out if data needed is there
- Need to convert MM addr to cache location

### MM to cache mapping

we maintain block size for MM and cache, easier to manage.

MM -> tag : index : offset

block mapping determined by index bits.

Cache -> valid : tag : cache block
-> 1 : t : BS

Storage of data in cache is random, so we need a mechanism to help us identify which MM block it belongs to.

To identify the mapping from MM to cache

1. Use index from MM to identify set index
2. Check line valid
3. Use tag to locate cache line
4. Use MM offset to find data in cache line

We can derive the values from the use case of the organisation

$$offset = log_2(block size)$$
$$index = log_2(# sets)$$
$$tag = 32 - index - offset$$

### Cache size

$$C = (1 + t + BS) * E * S$$

where E is the number of lines per set, S is the number of sets.

### Cache memory organisation

- Array of sets
- Each set contains 1 or more lines
- Each line holds a block of data
