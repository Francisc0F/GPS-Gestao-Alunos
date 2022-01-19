cmake_minimum_required(VERSION 3.21)
project(GPS C)

set(CMAKE_C_STANDARD 99)

add_executable(GPS main.c curso.c curso.h ucurricular.c ucurricular.h aluno.c aluno.h fileData.h)
