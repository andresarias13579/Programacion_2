cmake_minimum_required(VERSION 4.2)
project(rectagulo)

set(CMAKE_CXX_STANDARD 20)

add_executable(rectagulo main.cpp
        Bibliotecas/Rectangulo.cpp
        Bibliotecas/Rectangulo.h)
