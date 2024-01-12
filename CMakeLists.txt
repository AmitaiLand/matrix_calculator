cmake_minimum_required(VERSION 3.26)
project(matrix_calculator C)

set(CMAKE_C_STANDARD 11)

# Add all your source files to the executable
add_executable(matrix_calculator mainmat.c mymat.c)

