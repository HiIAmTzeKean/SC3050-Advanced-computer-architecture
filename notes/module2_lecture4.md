# ISA

## Categorisation

### instruction format

> big question, why do we need this many formats?
>
> [gives us flexibility when programming]

- register type
  - Rn n^th register
  - Rm m^th register
  - ALU processes both and returns output to
  - Rd the d^th register (destination)
- data transfer type
  - why Rt and not Rd?
    - ldr copies Rn to Rt
    - str copies Rt to Rn
  - Rn specifies the n^th register holding the value
  - with the address, ALU adds both
  - goes to MM and obtain the value and put in Rt t^th register
- immediate type
  - uses 12 bits for immediate value
  - saves 1 register
  - uses Rn and Rd
