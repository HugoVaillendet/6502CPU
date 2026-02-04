#include "CPU.h"
#include "instructions.h"

CPU create_cpu(void) {
    CPU cpu;

    cpu.reg.A = 0;
    cpu.reg.P = 0x20;
    cpu.reg.PC = 0;
    cpu.reg.S = 0;

    return cpu;
}

void cpu_loop(CPU *cpu, const uint8_t *program, size_t program_len) {

    cpu->reg.PC = 0;
    bool alive = true;

    while(alive == true) {

        uint8_t opcode = program[cpu->reg.PC];
        cpu->reg.PC += 1;

        switch (opcode) {
            case 0x00:
                BRK(cpu, program);
                printf("0x00\n");
                alive = false;
                break;

            case 0xA9:
                LDA(cpu, program);
                printf("0xA9\n");
                printf("%d\n", cpu->reg.A);
                break;
        
            default:
                break;
        }
    }
    printf("CPU Status Register P: 0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (cpu->reg.P >> i) & 1);
    }
    printf("\n");
}

void setFlag(CPU *cpu, Flag f) {
    switch (f) {
        case C :
            cpu->reg.P = cpu->reg.P | 0b00000001;
            break;
        case Z :
            cpu->reg.P = cpu->reg.P | 0b00000010;
            break;
        case I :
            cpu->reg.P = cpu->reg.P | 0b00000100;
            break;
        case D :
            cpu->reg.P = cpu->reg.P | 0b00001000;
            break;
        case B :
            cpu->reg.P = cpu->reg.P | 0b00010000;
            break;
        case V :
            cpu->reg.P = cpu->reg.P | 0b01000000;
            break;
        case N :
            cpu->reg.P = cpu->reg.P | 0b10000000;
            break;
        
        default:
            break;
    }
}

void clearFlag(CPU *cpu, Flag f) {
    switch (f) {
        case C :
            cpu->reg.P = cpu->reg.P & 0b11111110;
            break;
        case Z :
            cpu->reg.P = cpu->reg.P & 0b11111101;
            break;
        case I :
            cpu->reg.P = cpu->reg.P & 0b11111011;
            break;
        case D :
            cpu->reg.P = cpu->reg.P & 0b11110111;
            break;
        case B :
            cpu->reg.P = cpu->reg.P & 0b11101111;
            break;
        case V :
            cpu->reg.P = cpu->reg.P & 0b10111111;
            break;
        case N :
            cpu->reg.P = cpu->reg.P & 0b01111111;
            break;
        
        default:
            break;
    }
}

Flag getFlag(CPU *cpu) {
    if (cpu->reg.P & 0b00000001) return C;
    if (cpu->reg.P & 0b00000010) return Z;
    if (cpu->reg.P & 0b00000100) return I;
    if (cpu->reg.P & 0b00001000) return D;
    if (cpu->reg.P & 0b00010000) return B;
    if (cpu->reg.P & 0b01000000) return V;
    if (cpu->reg.P & 0b10000000) return N;
    
    return U;
}