# Cache performance

## Impact to performance

- Cache hit
  - CPU -> Cache -> CPU
- Cache miss
  - CPU -> Cache -> lower level -> CPU
- more levels will cause longer latency

## Cache miss in detail

- Detect miss
- Find victim
- Write back if dirty
- Request line from next level
- Transfer from next level
  - $Block size / bus width$
- Update tag

Can take 6 to 100 of cycles

### Factors affecting

- Temporal locality
- Spacial
- Cache organisation

We can reduce the reasons to be

- Compulsory miss
  - First reference to give block
- Capacity miss
  - Working set exceed cache capacity
- Conflict miss
  - Placement restriction (organisation)
  - Capacity within set

Ref:

- <https://stackoverflow.com/questions/33314115/whats-the-difference-between-conflict-miss-and-capacity-miss>
- <https://courses.cs.washington.edu/courses/cse378/02sp/sections/section9-2.html>

### Reducing cache miss

- Increase number blocks
  - Set * associativity -> $S /times E$
  - More blocks means more capacity
- Associativity
  - Higher reduces conflict miss but increase access time
  - We have more choices to pick from
- Block size
  - Larger block for more spacial locality
  - Although once exceed some size, performance is worst
  - Due to fewer placement choice due to more conflict miss
  - Miss penalty higher since we need to copy more

## Cache empirical performance

As we increase the associativity, we are able to obtain a lower miss rate for a
small cache size. It is no surprise that direct mapped performs the worst.

$$Exec Time = IC /times CPI /times time$$

To include the cache cost

$$Exec Time = IC /times (CPI_{ideal} + Memory Stall) /times time$$

$$Memory stall = \% Program Access /times Miss Rate /times Miss Penalty$$

## Multi level miss calculation

- L1 access
- L2 can be a hit or miss
- L3 (last level cache) could be hit or miss

## Average Memory Access Time

$$AMAT = Time For Hit + Miss Rate /times Miss Penalty$$

Average time to access memory for both hit and miss. Note we compute the figure
based on block cycles rather than absolute time.

## Question to clarify

- Why memory stall cycle for IM is 1 for the % program access ?

Response: The reason is because all instructions must be fetched from IM unlike
DM access where it is only affected by LD/ST instructions. This means the % of
program access for IM is 100%. The impact is, usually the stall from IM is higher
than DM even though miss rate for DM access is higher.
