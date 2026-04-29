cmake_minimum_required(VERSION 4.2)
project(qSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(qSort main.cpp
        Bilbiotecas/FuncionesDeOrdenacionGenerica.cpp
        Bilbiotecas/FuncionesDeOrdenacionGenerica.h
        Bilbiotecas/FuncionesDeEnteros.cpp
        Bilbiotecas/FuncionesDeEnteros.h)
