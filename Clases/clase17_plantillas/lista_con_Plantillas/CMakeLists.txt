cmake_minimum_required(VERSION 4.2)
project(lista_con_Plantillas)

set(CMAKE_CXX_STANDARD 20)

add_executable(lista_con_Plantillas main.cpp
        Bibliotecas/PlNodo.h
        Bibliotecas/PlLista.h
        Bibliotecas/Persona.cpp
        Bibliotecas/Persona.h)
