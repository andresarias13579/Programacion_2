cmake_minimum_required(VERSION 4.2)
project(CreaBiblioteca_Parte1)

set(CMAKE_CXX_STANDARD 20)

add_library(MisFunciones STATIC Bibliotecas/Operadores.cpp)

add_executable(CreaBiblioteca_Parte1 main.cpp
        Bibliotecas/Estructuras.h
        Bibliotecas/Operadores.cpp
        Bibliotecas/Operadores.h)

target_link_libraries(CreaBiblioteca_Parte1 MisFunciones)
