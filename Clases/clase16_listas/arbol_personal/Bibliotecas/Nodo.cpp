#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    inicializar();
}

void Nodo::inicializar() {
    izquierda = nullptr;
    derecha = nullptr;
}