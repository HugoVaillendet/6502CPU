#include "instructions.h"

void BRK(CPU *cpu, const uint8_t *program) {
    setFlag(cpu, B);
}

void LDA(CPU *cpu, const uint8_t *program) {
    uint8_t param = cpu->mem[cpu->reg.PC];
    cpu->reg.PC += 1;
    cpu->reg.A = param;
    setFlag(cpu, C);
}