cmake_minimum_required(VERSION 4.1)
project(MiSolucion_lecturaDeAlumnos)

set(CMAKE_CXX_STANDARD 20)

add_executable(MiSolucion_lecturaDeAlumnos main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h)
