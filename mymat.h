//
// Created by Amitai on 1/4/2024.
//

#ifndef MATRIX_CALCULATOR_MYMAT_H
#define MATRIX_CALCULATOR_MYMAT_H
// h.mymat

typedef struct {
    double data[4][4];
} mat;

void mat_read(mat *matrix);
void mat_print(mat *matrix);
void mat_add(mat *result, mat *matrix_a, mat *matrix_b);
void mat_sub(mat *result, mat *matrix_a, mat *matrix_b);
void mat_mul(mat *result, mat *matrix_a, mat *matrix_b);
void scalar_mul(mat *result, mat *matrix, double scalar);
void mat_trans(mat *result, mat *matrix);

#endif


