#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t A;
    uint8_t P;
    uint16_t PC;
    uint8_t S;
    uint8_t X;
    uint8_t Y;
} Register;

typedef struct {
    Register reg;
} CPU;

typedef enum {
    C,
    Z,
    I,
    D,
    B,
    U,
    V,
    N
} Flag;

void setFlag(CPU *cpu, Flag f);

CPU create_cpu(void);

CPU cpu_loop(CPU *cpu, const uint8_t *program, size_t program_len);