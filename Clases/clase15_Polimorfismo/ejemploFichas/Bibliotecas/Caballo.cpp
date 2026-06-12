#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Caballo.h"

void Caballo::imprime(ofstream &arch) const {
    arch<<left<<"CABALLO ";
    Ficha::imprime(arch);
}

void Caballo::mover(char direccion, int cantidad) {

}
