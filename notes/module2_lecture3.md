# ISA

## ARM ISA

- Simple and used in RISC
- 64-bit address bus
- 64-bit data
- 32-bit instruction
- 32 register files
  - Each register stores 64-bit data
  - X31 is known as the zero register

Note that the address uses a double word. A word is 4 bytes.
If we have a 64-bit address, we have $2^{64}$ locations. So we have $2^{64}$
memory words (divide by 4).

## Registers

- Enable and disable pin
- General registers have 2 read and 1 write port

## PC

- Holds a 64-bit address
- Increments by 4 since instructions are a word size

## Little vs Big Endian

- Little Endian has the smallest significant value at a smaller address
- Big Endian has the biggest significant value at a smaller address

## categorization

### Instruction Format

- Register
- Data
- Immediate format
- Conditional
- Conditional branch

### Functionality

- Arithmetic and Logic
  - add, sub
- Data Transfer
  - ld, st
- Conditional Branch
