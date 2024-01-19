#include "mymat.h"
#include <stdio.h>

#define MATRIX_SIZE 4

void mul_mat(mat *matrix_a, mat *matrix_b, mat *result) {
    mat matrix_temp;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            double sum = 0.0;
            for (int k = 0; k < 4; ++k) {
                sum += matrix_a->data[i * 4 + k] * matrix_b->data[k * 4 + j];
            }
            matrix_temp.data[i * 4 + j] = sum;
        }
    }
    for (int i = 0; i < 16; ++i) {
        result->data[i] = matrix_temp.data[i];
    }
}

void trans_mat(mat *matrix1, mat *matrix2) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            (matrix2 -> data)[i*4 + j] = (matrix1 -> data)[j*4 + i];
        }
    }
}

void mul_scalar(mat *matrix1,  double scalar, mat *matrix2)
{
    for (int i = 0; i < 16; ++i) {
        (matrix2 -> data)[i] = (matrix1 -> data)[i] * scalar;
    }
}

void add_mat(mat *matrix1, mat *matrix2, mat *matrix3) {
    for (int i = 0; i < 16; ++i) {
        (matrix3 -> data)[i] = (matrix1 -> data)[i] + (matrix2 -> data)[i];
    }
}

void sub_mat(mat *matrix1, mat *matrix2, mat *matrix3) {
    for (int i = 0; i < 16; ++i) {
        (matrix3 -> data)[i] = (matrix1 -> data)[i] - (matrix2 -> data)[i];
    }
}

void mat_set_element(mat *matrix, int location, double num) {
    (matrix -> data)[location] = num;
}
void print_mat(mat *matrix) {
    for (int i = 0; i < 16; ++i) {
        if(i % 4 == 3) {
            printf("%.2f\n", (matrix -> data)[i]);
        }
        else {
            printf("%.2f\t", (matrix -> data)[i]);
        }
    }
}
void mat_reset(mat *matrix)
{
    for (int i = 0; i < 16; ++i) {
        matrix->data[i] = 0;
    }
}



