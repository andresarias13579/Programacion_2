cmake_minimum_required(VERSION 3.31)
project(primerMetodo)

set(CMAKE_CXX_STANDARD 20)

add_executable(primerMetodo main.cpp
        Biblioteca/FuncionesAuxiliares.cpp
        Biblioteca/FuncionesAuxiliares.h)
