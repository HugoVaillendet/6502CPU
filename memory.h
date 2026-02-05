#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "CPU.h"

typedef enum {
    Immediate,
    ZeroPage,
    Absolute,
    ZeroPageX,
    ZeroPageY,
    AbsoluteX,
    AbsoluteY,
    IndirectX,
    IndirectY,
    None
} AddrMode;

uint8_t read8(CPU *cpu, uint16_t addr);
void write8(CPU *cpu, uint16_t addr, uint8_t data);
uint16_t read16(CPU *cpu, uint16_t addr);
void write16(CPU *cpu, uint16_t addr, uint16_t data);

uint16_t get_addr(CPU *cpu, AddrMode mode); 