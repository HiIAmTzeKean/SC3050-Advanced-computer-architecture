# Lab 4

run the code below to check your register files

```
set NREG 64
set scope_path "/test_bench_5_stage_pipeline/uut/dm"
for {set i 0} {$i < $NREG} {incr i} {
	set dm_value [get_value ${scope_path}/dmemory[$i]]
	puts "dmemory [$i] = $dm_value"
}
```

## part 1

@0
001F03FF
@1
00A06021
@2
00A07042
@3
00A08063
@4
00A00024
@5
001F03FF
@6
001F03FF
@7
00030084
@8
001F03FF
@9
001F03FF
@A
00C00024
@B
00220021
@C
001F03FF
@D
001F03FF
@E
07000081
@F
001F03FF
@10
001F03FF
@11
23FFFFF3
@12
001F03FF
@13
001F03FF

## part 2

this is the instructions that we need to run for the loop unroll. total of 5
stall cycles.

00A00024 //LDUR X4, [X1,#0]
00BFF025 //LDUR X5, [X1,#-1]
NOP
00030084 //ADD X4, X4, X3
000300A5 //ADD X5, X5, X3
00220021 //SUB X1, X1, X2
00C00024 //STUR X4, [X1, #0]
00DFF025 //STUR X5, [X1, #-1]
07000081 //CBZ X1, #4
NOP
NOP
23FFFFF5 //B#-11
NOP
NOP

@0
001F03FF
@1
00A06021
@2
00A07042
@3
00A08063
@4
00A00024
@5
00BFF025 
@5
001F03FF
@6
00030084
@7
000300A5
@8
00220021
@9
00C00024
@A
00DFF025
@B
07000081
@C
001F03FF
@D
001F03FF
@E
23FFFFF5
@F
001F03FF
@10
001F03FF
