cmake_minimum_required(VERSION 4.2)
project(arbol_personal)

set(CMAKE_CXX_STANDARD 20)

add_executable(arbol_personal main.cpp
        Bibliotecas/Empleado.cpp
        Bibliotecas/Empleado.h
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Arbol.cpp
        Bibliotecas/Arbol.h)
