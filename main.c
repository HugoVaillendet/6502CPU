#include <stdio.h>
#include "CPU.h"

int main() {

    uint8_t prgm[] = {0xA9, 0x05, 0x00};

    CPU cpu = create_cpu();

    cpu_loop(&cpu, prgm, sizeof(prgm)/sizeof(prgm[0]));
    
    return 0;
}