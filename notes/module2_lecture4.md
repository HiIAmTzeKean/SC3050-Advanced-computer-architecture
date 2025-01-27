# ISA

## Categorization

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
- conditional type
  - Note that the relative branching is always $N*4$ since the PC increments by
  a word. How we do this is left shift by 2.

### Addressing mode

- Register addressing
- base addressing
- immediate addressing
- pc-relative addressing

## Question to clarify

- for branching, assume address of size 4 bits. since it is signed number, what
  if i were to branch 0111, since we need to LLS, that becomes a -ve number.

Response: There is a sign extender that will take care of the shifting. The sign
value of the number will be preserved.
