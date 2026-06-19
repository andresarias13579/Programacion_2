#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    inicializar();
}

void Nodo::inicializar() {
    metrica = nullptr;
    siguiente = nullptr;
    anterior = nullptr;
}