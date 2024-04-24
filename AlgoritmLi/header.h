#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ROWS     10
#define COLS     10

#define startX   1
#define startY   1
#define finishX  10
#define finishY  10

float** allocation_memory(size_t rows, size_t cols, int data);

void print_field(float** field, size_t rows, size_t cols);

float** create_wall(float** field);


float** search_Li(float** field);