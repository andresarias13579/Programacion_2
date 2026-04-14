cmake_minimum_required(VERSION 4.2)
project(lecturaDeAlumnos)

set(CMAKE_CXX_STANDARD 20)

add_executable(lecturaDeAlumnos main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h)
