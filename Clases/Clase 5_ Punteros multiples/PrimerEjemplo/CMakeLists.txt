cmake_minimum_required(VERSION 3.31)
project(PrimerEjemplo)

set(CMAKE_CXX_STANDARD 20)

add_executable(PrimerEjemplo main.cpp
        "Biblioteca/Funciones Auxiliares.cpp"
        "Biblioteca/Funciones Auxiliares.h"
)
