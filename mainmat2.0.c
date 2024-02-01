
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymat.h"
#include "mymat.c"

//TODO:make a function that checks if the string is a double
//TODO:make in general handling wrong inputs and giving them the reason its wrong
//TODO:print the same line that was received as an input
//TODO:make it compatible for ubuntu
//TODO:make comments

mat* mat_identify(char *mat_name, mat* MAT_A, mat* MAT_B, mat* MAT_C,  mat* MAT_D,  mat* MAT_E, mat* MAT_F) /*matrix identification function*/
{
    if(mat_name[4] == 'A')
        return MAT_A;
    if(mat_name[4] == 'B')
        return MAT_B;
    if(mat_name[4] == 'C')
        return MAT_C;
    if(mat_name[4] == 'D')
        return MAT_D;
    if(mat_name[4] == 'E')
        return MAT_E;
    if(mat_name[4] == 'F')
        return MAT_F;
    printf("Undefined matrix name"); /*default message for an undefined matrix name*/
}

int main() {
    char command[100];
    mat MAT_A, MAT_B,  MAT_C,  MAT_D,  MAT_E,  MAT_F;
    mat_reset(&MAT_A), mat_reset(&MAT_B), mat_reset(&MAT_C), mat_reset(&MAT_D), mat_reset(&MAT_E), mat_reset(&MAT_F);
    while (1) {


        printf("Enter a command (or 'stop' to exit): \n");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "stop") == 0) {
            printf("Exiting the program.\n");
            break;
        }

        char *token = strtok(command, " ");
        if (token == NULL) {
            printf("Undefined command name"); /*default message for an undefined command*/
            continue;
        }

        switch (token[0]) {
            case 'a': /*checking if the user entered a matrix adding command*/
                if (strcmp(token, "add_mat") == 0) {
                    char *element = strtok(NULL, ",");
                    mat* currMat1 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    element = strtok(NULL, ", ");
                    mat* currMat2 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    element = strtok(NULL, ", ");
                    mat* currMat3 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    add_mat(currMat1, currMat2, currMat3);
                }
                else {
                    printf("Undefined command name");/*default message for an undefined command*/
                }
                break;

            case 's': /*checking if the user entered a matrix subtracting command*/
                if (strcmp(token, "sub_mat") == 0) {
                    char *element = strtok(NULL, ",");
                    mat* currMat1 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    element = strtok(NULL, ", ");
                    mat* currMat2 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    element = strtok(NULL, ", ");
                    mat* currMat3 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    sub_mat(currMat1, currMat2, currMat3);
                }
                else {
                    printf("Undefined command name");/*default message for an undefined command*/
                }
                break;

            case 'm': /*checking if the user entered a matrix multiplication command*/
                switch (token[4]) {
                    case 's':
                        if (strcmp(token, "mul_scalar") == 0) {
                            char *element = strtok(NULL, ",");
                            mat* currMat1 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                            element = strtok(NULL, ", ");
                            double scalar =  (double)*element;
                            element = strtok(NULL, ", ");
                            mat* currMat2 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                            mul_scalar(currMat1, scalar, currMat2);
                        }
                        else {
                            printf("Undefined command name");/*default message for an undefined command*/
                        }
                        break;
                    case 'm':
                        if (strcmp(token, "mul_mat") == 0) {
                            char *element = strtok(NULL, ",");
                            mat* currMat1 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                            element = strtok(NULL, ", ");
                            mat* currMat2 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                            element = strtok(NULL, ", ");
                            mat* currMat3 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                            mul_mat(currMat1, currMat2, currMat3);
                        }
                        else {
                            printf("Undefined command name");/*default message for an undefined command*/
                        }
                        break;
                }
                break;
            case 't':
                if (strcmp(token, "trans_mat") == 0) {
                    char *element = strtok(NULL, ",");
                    mat* currMat1 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    element = strtok(NULL, ", ");
                    mat* currMat2 =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    trans_mat(currMat1, currMat2);
                }
                else {
                    printf("Undefined command name");/*default message for an undefined command*/
                }
                break;

            case 'p': /*checking if the user entered a matrix printing command*/
                if (strcmp(token, "print_mat") == 0) {
                    char *element = strtok(NULL, ",");
                    mat* currMat =  mat_identify(element, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    print_mat(currMat);
                }
                else {
                    printf("Undefined command name");/*default message for an undefined command*/
                }
                break;

            case 'r': /*checking if the user entered a matrix reading command*/
                if (strcmp(token, "read_mat") == 0) {
                    char* mat_name = strtok(NULL, " ");
                    mat* currMat =  mat_identify(mat_name, &MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F);
                    int zero = 0;
                    for (int i = 0; i < 16; ++i) {
                        char *element = strtok(NULL, ",");
                        if(element == NULL){
                            zero = i;
                            break;
                        }
                        int num = atoi(element);
                        mat_set_element(currMat,i, num);
                        zero++;
                    }
                    for (int i = zero; i < 16; ++i) {
                        mat_set_element(currMat,i, 0);
                    }
                }
                else
                {
                    printf("Undefined command name");/*default message for an undefined command*/
                }
                break;
            default: /*defining the default error message*/
                printf("Undefined command name");/*default message for an undefined command*/
                break;
        }
    }

    return 0;
}
