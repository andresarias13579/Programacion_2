cmake_minimum_required(VERSION 4.2)
project(Lab09_2023_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab09_2023_1 main.cpp
        Bibliotecas/Alumno.cpp
        Bibliotecas/Alumno.h
        Bibliotecas/Escala.cpp
        Bibliotecas/Escala.h
        Bibliotecas/Presencial.cpp
        Bibliotecas/Presencial.h
        Bibliotecas/Semiprecensial.cpp
        Bibliotecas/Semiprecensial.h
        Bibliotecas/Virtuales.cpp
        Bibliotecas/Virtuales.h
        Bibliotecas/Boleta.cpp
        Bibliotecas/Boleta.h
        Bibliotecas/Tesoreria.cpp
        Bibliotecas/Tesoreria.h)
