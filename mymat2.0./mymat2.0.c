
#include "mymat.h"
#include <stdio.h>

#define MATRIX_SIZE 4

void mul_mat(mat *matrix_a, mat *matrix_b, mat *result) { /*matrix multiplication function*/
    int i = 0;
    int j = 0;
    int k = 0;
    double sum = 0.0;
    mat matrix_temp;
    for (i; i < 4; ++i) {
        for (j; j < 4; ++j) {
            for (k; k < 4; ++k) {
                sum += matrix_a->data[i * 4 + k] * matrix_b->data[k * 4 + j];
            }
            matrix_temp.data[i * 4 + j] = sum;
        }
    }
    for (i = 0; i < 16; ++i) {
        result->data[i] = matrix_temp.data[i];
    }
}

void trans_mat(mat *matrix1, mat *matrix2) { /*matrix transposing function*/
    int i = 0;
    int j = 0;
    for (i; i < 4; ++i) {
        for (j; j < 4; ++j) {
            (matrix2 -> data)[i*4 + j] = (matrix1 -> data)[j*4 + i];
        }
    }
}

void mul_scalar(mat *matrix1,  double scalar, mat *matrix2) /*matrix multiplication by scalar function*/
{
    int i = 0;
    for (i; i < 16; ++i) {
        (matrix2 -> data)[i] = (matrix1 -> data)[i] * scalar;
    }
}

void add_mat(mat *matrix1, mat *matrix2, mat *matrix3) { /*matrix addition function*/
    int i = 0;
    for (i; i < 16; ++i) {
        (matrix3 -> data)[i] = (matrix1 -> data)[i] + (matrix2 -> data)[i];
    }
}

void sub_mat(mat *matrix1, mat *matrix2, mat *matrix3) { /*matrix subtraction function*/
    int i = 0;
    for (i; i < 16; ++i) {
        (matrix3 -> data)[i] = (matrix1 -> data)[i] - (matrix2 -> data)[i];
    }
}

void mat_set_element(mat *matrix, int location, double num) { /*matrix function that places the received element in the selected place in the matrix*/
    (matrix -> data)[location] = num;
}
void print_mat(mat *matrix) {
    int i = 0;
    for (i; i < 16; ++i) {
        if(i % 4 == 3) {
            printf("%.2f\n", (matrix -> data)[i]);
        }
        else {
            printf("%.2f\t", (matrix -> data)[i]);
        }
    }
}
void mat_reset(mat *matrix) /*matrix resetting to all zero's function*/
{
    int i = 0;
    for (i; i < 16; ++i) {
        matrix->data[i] = 0;
    }
}


