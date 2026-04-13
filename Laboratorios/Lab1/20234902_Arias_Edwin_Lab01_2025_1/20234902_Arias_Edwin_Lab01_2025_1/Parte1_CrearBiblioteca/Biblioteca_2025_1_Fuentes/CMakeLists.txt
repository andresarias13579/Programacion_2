cmake_minimum_required(VERSION 4.1)
project(Biblioteca_2025_1_Fuentes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Biblioteca_2025_1_Fuentes main.cpp
        Bibliotecas/CadenaDeCaracteres.h
        Bibliotecas/OperadoresSobreCargados.cpp
        Bibliotecas/OperadoresSobreCargados.h
        main.cpp)
