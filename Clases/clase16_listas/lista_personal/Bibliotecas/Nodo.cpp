#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    inicializa();
}
void Nodo::inicializa() {
    siguiente = nullptr;
}