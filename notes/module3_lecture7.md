# Pipelining

## Clock cycle per instruction

$CPI = \text{Total CPU Cycles} / \text{Total Instructions Executed}$

We are concerned with the # of instructions here. Decomposing and instruction into
its blocks does not affect the # of instruction.

High CPI indicates that the CPU is inefficient, needs more cycles to finish given
instruction. Low CPI is great, but we must also take note of the lenght of each
cycle to be fair.

## Single cycle

### Shortening clock cycle

We can visualize the process as a single clock cycle for the entire lifecycle.
For example, if the lifecycle has 5 stages, then we can say that for 1 cycle
of a low and high signal, we complete 5 stages.

Whats the adv and disadv?

- low cycle per instructions but long clock period
- the entire cycle must wait for the slowest operation
- single bottleneck holds up the entire cycle

This can be further refined, that is, tag the clock cycle to each stage. But the
problems still remains, we need 5 clock cycles to finish 1 full task even those
cycles are shorter.

Whats the adv and disadv?

- we now get shorter clock period but we have a higher CPI.

Instead,

## Register latency

## Instruction independence

## Question to clarify

- When is `sign extend` needed in the 4 types of instruction?
- How to progressively add MUX to architecture to enable flexibility