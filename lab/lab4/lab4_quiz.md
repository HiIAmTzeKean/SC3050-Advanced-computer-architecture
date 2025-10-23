# Practise question

You can assume for all questions that this is a 5 stage pipeline.
Read and write can happen simultaneously. You might need to rearrage
some of the instruction for the correct expected output. If not stated
execute the instruction on a as-is basis.

## Question 1

Given X5 is initiatized to 14, all others to 0. Assume all values in memory is 10.

LDUR X5, [X0, 0XA]
ADD X5. X5, X5

What is X5 in decimal? What is X5 in hexa?

Will the output of X5 be different after adding NOP?

How many NOP do you need to add to get the correct output?

Where should you add the NOP?

What is the smallest number of NOP that you can add to get the correct
output?

## Question 2

Following from question 1.
Assume X1 is 0.

LDUR X5, [X1, #1]
ADDI X5, X5, #5
ADDI X1, X1, #1
CBNZ X1, #0

How many loops will run?

What is the value of X5?

How many NOP must you add to get the expected correct result?

If I want to run the loop instead for 5 times what should be changed?
