#include<stdio.h>
#include"include/rv32i.h"
#include "program.h"
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
    for (int i = 0; i < program_bin_len; i++)
    {
        write_byte_to_address_space(program_addr + i,program_bin[i],&cpu);
    }
    while (decode(&cpu,fetch_instr(&cpu))== 0)
    {
    }
    return cpu.sys_err_table;
}
