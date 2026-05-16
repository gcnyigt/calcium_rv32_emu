#include<stdio.h>
#include"include/rv32i.h"
unsigned char message[] = "Calcium version 0.01\n";//21
word program[] = {
    // --- INITIALIZATION---
    0x0000f0b3, // and x1, x1, x0  
    0x0000f133, // and x2, x2, x0   
    0x0000f1b3, // and x3, x3, x0   
    0x01500193, // addi x3, x0, 21   
    // --- ADDRESSING---
    0x900002b7, // lui x5, 0x90000  
    0x800010b7, // lui x1, 0x80001  
    // --- LOOP---
    0x00008203, // lb x4, 0(x1)     
    0x00428023, // sb x4, 0(x5)     
    0x00110113, // addi x2, x2, 1 
    0x00108093, // addi x1, x1, 1 
    0xfe3148e3, // blt x2, x3, -16  
    0x0//nop padding
    };
int main()
{
    rv32i cpu;
    cpu.pc = 0;
    for (int i = 0; i < 32; i++)
    {
        cpu.x[i] = 0;
    }

    cpu.sys_err_table = 0;
    const word program_addr = 0x80000000;
    const word data_addr = 0x80001000;
    for (int i = 0; i < 16; i++)
    {
        write_word_to_address_space(program_addr + 4*i,program[i],&cpu);
    }
    for (int i = 0; i < 21; i++)
    {
        write_byte_to_address_space(data_addr + i,message[i],&cpu);
    }
    while (cpu.sys_err_table == 0)
    {
        decode(&cpu,fetch_instr(&cpu));
    }
    return cpu.sys_err_table;
}