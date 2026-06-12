cmake_minimum_required(VERSION 4.1)
project(punterosHerencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(punterosHerencia main.cpp
        Bibliotecas/Base.cpp
        Bibliotecas/Base.h
        Bibliotecas/Derivada1.cpp
        Bibliotecas/Derivada1.h
        Bibliotecas/Derivada2.cpp
        Bibliotecas/Derivada2.h)
