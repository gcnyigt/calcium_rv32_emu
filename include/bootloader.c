#include"bootloader.h"
word bootloader[] = {
    0x800000b7, // LUI x1, 0x80000
    0x00008067, // JALR x0, 0(x1)
    0x00000000  // NOP Padding
};