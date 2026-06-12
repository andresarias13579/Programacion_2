#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Alfil.h"

void Alfil::imprime(ofstream &arch) const {
    arch<<left<<"ALFIL ";
    Ficha::imprime(arch);
}

void Alfil::mover(char direccion, int cantidad) {
    //arriba - izquierda
    if (direccion == 'P' or direccion == 'p') {
        set_fila(get_fila()-cantidad);
        set_columna(get_columna()-cantidad);
    }
    //arriba - derecha
    if (direccion == 'Q' or direccion == 'q') {
        set_fila(get_fila()-cantidad);
        set_columna(get_columna()+cantidad);
    }
    //abajo - derecha
    if (direccion == 'R' or direccion == 'r') {
        set_fila(get_fila()+cantidad);
        set_columna(get_columna()+cantidad);
    }
    //abajo - izquierda
    if (direccion == 'S' or direccion == 's') {
        set_fila(get_fila()+cantidad);
        set_columna(get_columna()-cantidad);
    }
}

