cmake_minimum_required(VERSION 3.31)
project(operadoresSobrecargados)

set(CMAKE_CXX_STANDARD 20)

add_executable(operadoresSobrecargados main.cpp
        Bibliotecas/Persona.h
        Bibliotecas/sobreCargas.cpp
        Bibliotecas/sobreCargas.h
)
