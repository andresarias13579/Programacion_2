cmake_minimum_required(VERSION 3.31)
project(OperadoresSobrecargadosComplejo)

set(CMAKE_CXX_STANDARD 20)

add_executable(OperadoresSobrecargadosComplejo main.cpp
        Biblioteca/Persona.h
        Biblioteca/Empleados.h
        Biblioteca/OperadoresSobrecargados.cpp
        Biblioteca/OperadoresSobrecargados.h)
