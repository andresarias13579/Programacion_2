cmake_minimum_required(VERSION 3.31)
project(UsarBibliotecaPersonal)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsarBibliotecaPersonal main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L\"${CMAKE_CURRENT_SOURCE_DIR}/MisBibliotecas\"")

target_link_libraries(UsarBibliotecaPersonal PRIVATE Personal)
