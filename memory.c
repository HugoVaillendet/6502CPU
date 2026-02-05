#include "memory.h"

uint8_t read8(CPU *cpu, uint16_t addr) {
    return cpu->mem[addr];
}

void write8(CPU *cpu, uint16_t addr, uint8_t data) {
    cpu->mem[addr] = data;
}

uint16_t read16(CPU *cpu, uint16_t addr) {
    uint16_t lowB = read8(cpu, addr);
    uint16_t highB = read8(cpu, addr + 1);
    return (highB << 1) | lowB;
}

void write16(CPU *cpu, uint16_t addr, uint16_t data) {
    uint16_t lowB = (data >> 8) & 0b11111111;
    uint16_t highB = data & 0b11111111;
    write8(cpu, addr, lowB);
    write8(cpu, addr + 1, highB);
}

uint16_t get_addr(CPU *cpu, AddrMode mode) {
    switch (mode) {
        case Immediate:
            return cpu->reg.PC;
            break;
        case ZeroPage:
            return (uint16_t)read8(cpu, cpu->reg.PC);
            break;
        case Absolute:
            return read16(cpu, cpu->reg.PC);
            break;
        case ZeroPageX: {
            uint8_t position = read8(cpu, cpu->reg.PC);
            return (uint16_t)(uint8_t)(position + cpu->reg.X);
            break;
        }
        case ZeroPageY: {
            uint8_t position = read8(cpu, cpu->reg.PC);
            return (uint16_t)(uint8_t)(position + cpu->reg.Y);
            break;
        }
        case AbsoluteX: {
            uint16_t position = read16(cpu, cpu->reg.PC);
            return (uint16_t)(position + (uint16_t)cpu->reg.X);
            break;
        }
        case AbsoluteY: {
            uint16_t position = read16(cpu, cpu->reg.PC);
            return (uint16_t)(position + (uint16_t)cpu->reg.Y);
            break;
        }
    
        default:
            exit(-1);
            break;
    }
}