#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "BibliotecaEnteros.h"

void * leeNumeros(ifstream &arch) {
    int *dato = new int;
    arch >> *dato;
    if (arch.eof()) return nullptr;
    return (void*)dato;
}
int compararEnteros(const void* a, const void* b) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    return valA - valB;
}
