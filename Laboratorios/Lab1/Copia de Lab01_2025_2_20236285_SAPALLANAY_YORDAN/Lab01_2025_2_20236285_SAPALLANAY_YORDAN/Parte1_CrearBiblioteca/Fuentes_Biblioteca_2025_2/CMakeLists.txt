cmake_minimum_required(VERSION 4.0)
project(Fuentes_Biblioteca_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_library(Sobrecarga STATIC MiBiblioteca/Sobrecarga.cpp)

add_executable(Fuentes_Biblioteca_2025_2 main.cpp
        MiBiblioteca/Sobrecarga.cpp
        MiBiblioteca/Sobrecarga.h
        MiBiblioteca/Funciones.cpp
        MiBiblioteca/Funciones.h
)

target_link_libraries(Fuentes_Biblioteca_2025_2 Sobrecarga)