#include "header.h"

float** allocation_memory(size_t rows, size_t cols, int data) {

    float** field;
    field = (float**)malloc(rows * sizeof(float*));

    for (int i = 0; i < cols; i++)
    {
        field[i] = (float*)malloc(cols * sizeof(float));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            field[i][j] = -1.0;
        }
    }

    return field;
}

void print_field(float** field, size_t rows, size_t cols) {

    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        printf("   ");
        for (int j = 0; j < cols; j++)
        {
            printf("%.0f ", field[i][j]);
        }
        printf("\n");
    }
}

float** create_wall(float** field) {

    for (int i = 0; i < 9; i++) {
        field[1][i] = -2.0;
    }

    return field;
}