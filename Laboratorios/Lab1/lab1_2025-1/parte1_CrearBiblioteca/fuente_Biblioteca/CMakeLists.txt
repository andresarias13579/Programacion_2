cmake_minimum_required(VERSION 4.2)
project(fuente_Biblioteca)

set(CMAKE_CXX_STANDARD 20)

add_library(MisOperadoers STATIC Bibliotecas/OperadoresSobreCargados.cpp)

add_executable(fuente_Biblioteca main.cpp
        Bibliotecas/CadenaDeCaracteres.h
        Bibliotecas/OperadoresSobreCargados.cpp
        Bibliotecas/OperadoresSobreCargados.h)

target_link_libraries(fuente_Biblioteca MisOperadoers)
