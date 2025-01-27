# Control hazards

Branching will cause stalls as execution sequence changes.

branch penalty

note pc updated only at data mem stage for LEGv8

## Reduction of stall from control hazards

### Conservative handling

stall immediately, wait for outcome

We could also try to push the update of the PC earlier such as in EXEC stage
so there there is only 2 stall.

early evaluation of PC in the decode cycle is also possible with hardware changes
such that there is only 1 stall.

### Branch prediction

predict if branch will be taken. can improve performance by 50%.

### Static branch prediction

we assume that the behavior is predictable.

predict-not-taken: assume instruction exec in sequence, flush if branch taken

predict-taken: same like conservative way. But that means we have to wait till branch
addr is known. So branch penalty no changes!

Delayed branch: use some other independent instruction to fill the stall slot

### Dynamic branch prediction

Decision may change depending on the exec history, unpredictable in nature.

one-bit prediction

- there are 2 possible states
- transition of states based on actual route
- limited accuracy when the state can change with various pattern

two-bit prediction

- Gives rise to more flexibility
- add hysteresis to predictor so that prediction does not change to definite form
  on a single outcome.
- the transition between each stage is also based on taken/not-taken
- Note that we would need more hardware to model the states

multi-bit prediction

- Bimodal prediction
- has a counter to determine prediction

## Question to clarify

- what is the difference between control and pipeline hazard?
- Are flush and stall able to be done in the same step? do we count them separately
  for the total branch penalty?

![early_evaluation_branch](data/early_evaluation_branch.png)

- how is this possible? flags are set and determined in ALU, how can we push to
  decode stage.
- read up on bimodal prediction
