cmake_minimum_required(VERSION 4.2)
project(lista_personal)

set(CMAKE_CXX_STANDARD 20)

add_executable(lista_personal main.cpp
        Bibliotecas/Empleado.cpp
        Bibliotecas/Empleado.h
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Lista.cpp
        Bibliotecas/Lista.h)
