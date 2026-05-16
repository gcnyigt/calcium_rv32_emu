#include"terminal.h"
#include <stdio.h>
int terminal(word internal_addr,byte data){
    if (internal_addr == 0)
    {
        terminalbuffer[0x4] = 1;
        putchar(data);
        fflush(stdout);
    }
    terminalbuffer[internal_addr] = data;
    terminalbuffer[0x4] = 0;
    return 0;

}