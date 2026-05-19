.section .text
.globl _start
_start:
li x2,0
li x3,19
la x1,msg_
li x5,0x90000000
loop:
lb x4,0(x1)
sb x4,0(x5)
add x1 ,x1,1
add x2, x2, 1
blt x2, x3, loop
msg_:
    .string "Calcium Test Code!\n"
