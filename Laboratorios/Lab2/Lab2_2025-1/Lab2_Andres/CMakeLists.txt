cmake_minimum_required(VERSION 4.2)
project(Lab2_Andres)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2_Andres main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h
        Bibliotecas/Estructuras.h
        Bibliotecas/OperadoresSobrecargados.cpp
        Bibliotecas/OperadoresSobrecargados.h)
