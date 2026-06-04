cmake_minimum_required(VERSION 4.1)
project(Ejemplo_circulo_cilindro_tuvo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ejemplo_circulo_cilindro_tuvo main.cpp
        Bibliotecas/Circulo.h
        Bibliotecas/Circulo.cpp
        Bibliotecas/Circulo.cpp
        Bibliotecas/Cilindro.cpp
        Bibliotecas/Cilindro.h
)
