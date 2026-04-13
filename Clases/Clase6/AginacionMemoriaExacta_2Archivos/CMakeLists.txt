cmake_minimum_required(VERSION 4.2)
project(AginacionMemoriaExacta_2Archivos)

set(CMAKE_CXX_STANDARD 20)

add_executable(AginacionMemoriaExacta_2Archivos main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h)
