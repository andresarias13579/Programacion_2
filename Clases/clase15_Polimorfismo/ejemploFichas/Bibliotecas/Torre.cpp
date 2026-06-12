#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Torre.h"

void Torre::imprime(ofstream &arch) const {
    arch<<left<<"TORRE     ";
    Ficha::imprime(arch);
}

void Torre::mover(char direccion, int cantidad) {
    //arriba
    if (direccion == 'P' or direccion == 'p') {
        set_fila(get_fila()-cantidad);
    }
    //derecha
    if (direccion == 'Q' or direccion == 'q') {
        set_columna(get_columna()-cantidad);
    }
    //abajo
    if (direccion == 'R' or direccion == 'r') {
        set_fila(get_fila()+cantidad);
    }
    //arriba
    if (direccion == 'S' or direccion == 's') {
        set_columna(get_columna()+cantidad);
    }
}
