cmake_minimum_required(VERSION 4.1)
project(ejemploFichas)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejemploFichas main.cpp
        Bibliotecas/Ficha.cpp
        Bibliotecas/Ficha.h
        Bibliotecas/Torre.cpp
        Bibliotecas/Torre.h
        Bibliotecas/Alfil.cpp
        Bibliotecas/Alfil.h
        Bibliotecas/Caballo.cpp
        Bibliotecas/Caballo.h)
