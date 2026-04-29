cmake_minimum_required(VERSION 4.2)
project(listasGenericas)

set(CMAKE_CXX_STANDARD 20)

add_executable(listasGenericas main.cpp
        Bibliotecas/BibliotecaListaGenerica.cpp
        Bibliotecas/BibliotecaListaGenerica.h
        Bibliotecas/FuncionesDeEnteros.cpp
        Bibliotecas/FuncionesDeEnteros.h
        Bibliotecas/FuncionesDeCadenas.cpp
        Bibliotecas/FuncionesDeCadenas.h
        Bibliotecas/FuncionesDePunterosVoid.cpp
        Bibliotecas/FuncionesDePunterosVoid.h)
