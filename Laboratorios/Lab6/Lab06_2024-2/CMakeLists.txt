cmake_minimum_required(VERSION 4.2)
project(Lab06_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab06_2024_2 main.cpp
        Bibliotecas/Cliente.cpp
        Bibliotecas/Cliente.h
        Bibliotecas/Plato.cpp
        Bibliotecas/Plato.h
        Bibliotecas/Restaurante.cpp
        Bibliotecas/Restaurante.h)
