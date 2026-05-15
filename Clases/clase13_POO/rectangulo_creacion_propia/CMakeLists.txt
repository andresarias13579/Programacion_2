cmake_minimum_required(VERSION 4.1)
project(rectangulo_creacion_propia)

set(CMAKE_CXX_STANDARD 20)

add_executable(rectangulo_creacion_propia main.cpp
        Bibliotecas/Rectangulo.cpp
        Bibliotecas/Rectangulo.h)
