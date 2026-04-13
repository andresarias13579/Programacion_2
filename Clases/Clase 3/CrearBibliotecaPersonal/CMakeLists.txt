cmake_minimum_required(VERSION 3.31)
project(CrearBibliotecaPersonal)

set(CMAKE_CXX_STANDARD 20)

add_library(Personal STATIC MisBibliotecas/Operadores.cpp)

add_executable(CrearBibliotecaPersonal main.cpp)

target_link_libraries(CrearBibliotecaPersonal Personal)
