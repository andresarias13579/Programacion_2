cmake_minimum_required(VERSION 4.2)
project(Parte2_UsarBiblioteca)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte2_UsarBiblioteca main.cpp
        MisBibliotecas/FuncionesAuxiliares.cpp
        MisBibliotecas/FuncionesAuxiliares.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L\"${CMAKE_CURRENT_SOURCE_DIR}/MisBibliotecas\"")

target_link_libraries(Parte2_UsarBiblioteca PRIVATE MisFunciones)
