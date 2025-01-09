# Module 1

Different types of computing system

embedded computer

- mobile phone
- smart watch

how did we get to where we are in terms of computing performance?

growth of processor wsa increasing to year 2005. Frequency of processor became
stale due to power dissipation issues.

## Take away

- key feature of computer architecture
- Performance metric and enhancement
- Power dissipation
- Power metrics
- Low power design

## Key feature of computer

- ALU
  - logical operations
- Control unit
- Memory
- I/O
- Bus system

CPU contains

- ALU
- Storage (cache)
- Control unit

Outside CPU

- I/O
- Bus
- Memory

## Computer system

Von neumann architecture

- Mem holds data and instructions
- 1 mem access per clock cycle

Harvard

- Separate mem for data and instruction
- 1 clock cycle access both data and instruct
- Used in DSP

## Computer Architecture

- ISA
- Micro architecture (Computer organisation)
- System design

## Design goals

- Functional requirements
  - Meet needs of demand
  - Constraint
- Reliability
  - Mission critical apps
  - Fault tolerance
- Cost
- Performance
- Power consumption

## Performance metric

- Execution time
  - $time_{end} - time_{start}$
- Performance
  - $\frac{1}{exec time}$
- Speedup
  - $speedup = \frac{perf_a}{perf_b}$
  - since $perf$ is inversely proportional to time then
  - $speedup = \frac{perf_a}{perf_b} = \frac{time_b}{time_a}$
  - $speedup = \frac{1}{[1-E] + \frac{E}{S}}$ where E is the fraction of the
  code that is being enhanced
- Amdahl's Law
  - Tells us $speedup_{max}$
  - $\lim_{s\to\infty} \frac{1}{[1-E] + \frac{E}{S}} = \frac{1}{[1-E]}$, where
  $E$ is the fraction of the enhanced component
  - We can view $1-E$ as the non-enhanced component, the greater the non-enhancement
  fraction, the smaller the inverse, and thus the smaller the speedup
  - Note that the graph is exponential in nature
  - What this limit represents is the serial component of the program that cannot
  be parallised and is a cost that we cannot reduce

### Factors that affect exec time

Known as IRON LAW

- IC
  - Program dependent
  - ISA
- CPI (Clock per instruct)
  - ISA
  - Datapath design
  - Parallel and pipelining
- T (Clock period)
  - Clock period
  - Datapath design

## Performance enhancement

### Challenges of enhancement

- Decreasing T (clock cycle time)
  - AKA increase clock frequency
  - leads to increase power consumption
  - memory op take longer than clock period leading to memory-wall problem
  (CPU wait for mem)
- Reduce IC
  - But instruct will be more complex causing CPI to increase
  - Multi-issue processor such as verilog to parallelise instruct
- Reduce CPI
  - pipelining in datapath
  - Multi-issue processor such as verilog to parallelise instruct
