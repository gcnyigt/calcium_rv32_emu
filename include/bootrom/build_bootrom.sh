#!/bin/bash
echo "Building bootrom"
riscv64-linux-gnu-as -march=rv32i -mabi=ilp32 bootrom.s -o bootrom.o
riscv64-linux-gnu-ld -m elf32lriscv -Ttext=0x0 bootrom.o -o bootrom.elf
echo "Generating hex code"
riscv64-linux-gnu-objcopy -O binary bootrom.elf bootrom.bin
xxd -i bootrom.bin > bootrom_hex.h