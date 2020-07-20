#pragma once
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>

FILE* open(char *argv);

void extract(uint8_t *uint8, FILE* f);

uint32_t sum(uint32_t num1, uint32_t num2);
