cmake_minimum_required(VERSION 4.2)
project(AplicacionConBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(AplicacionConBibliotecaEstatica main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L\"${CMAKE_CURRENT_SOURCE_DIR}/MisFunciones\"")

target_link_libraries(AplicacionConBibliotecaEstatica PRIVATE MisOperadoers)
