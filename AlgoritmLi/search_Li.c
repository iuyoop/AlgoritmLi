#include "header.h"

static int wall = -2, start = 0.0, finish = -1;
static int Ox1[] = { 1, -1, 0, 0  };
static int Oy1[] = { 0, 0, 1, -1  };
static int Ox2[] = { 1, -1, -1, 1 };
static int Oy2[] = { 1, -1, 1, -1 };

float** search_Li(float** field) {

    field[startX - 1][startY - 1] = start;

    float data  = 0.0;
    int found = 0;
    int temp_j = 0, temp_i = 0;
    float counter = 1.0;
    int flag_1 = 0, flag_2 = 0;

    while (found == 0) {

        found = 1;
        for (int i = 0; i < ROWS; i++) {

            for (int j = 0; j < COLS; j++) {

                if (field[i][j] == data) {

                    for (int k = 0; k < 4; k++) {

                        int newX = i + Ox1[k];
                        int newY = j + Oy1[k];
                        if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && field[newX][newY] == -1.0) {

                            field[newX][newY] = data + 1.0;
                            found = 0;
                            
                        }
                    }                   
                 }
            }
        }
        data = data + 1.0;
    }

    found = 0; 
    data = 0;
    while (found == 0) {

        found = 1;
        for (int i = 0; i < ROWS; i++) {

            for (int j = 0; j < COLS; j++) {

                if (field[i][j] == data) {

                    for (int k = 0; k < 4; k++) {

                        int newX = i + Ox2[k];
                        int newY = j + Oy2[k];
                        if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && field[newX][newY] != -2.0) {

                            field[newX][newY] = data + 2.0;
                            found = 0;
                        }
                    }
                }
            }
        }
        data = data + 2.0;
    }

    if (field[finishX - 1][finishY - 1] == -1)
        printf("\n | No way | \n");
    else
        printf(" | Short cut : %.0f |", field[finishX - 1][finishY -1]);
   
    return field;
}