//
// Created by Amitai on 1/4/2024.
//

#ifndef MATRIX_CALCULATOR_MYMAT_H
#define MATRIX_CALCULATOR_MYMAT_H
// h.mymat

typedef struct {
    double data[16];
} mat;
void print_mat(mat *matrix);
void add_mat(mat *result, mat *matrix_a, mat *matrix_b);
void sub_mat(mat *result, mat *matrix_a, mat *matrix_b);
void mul_mat(mat *matrix_a, mat *matrix_b, mat *result);
void mul_scalar(mat *matrix, double scalar, mat *result);
void trans_mat(mat *result, mat *matrix);
void mat_set_element(mat *matrix, int location, double num);
void mat_reset(mat *matrix);

#endif


