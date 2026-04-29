#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesDeEnteros.h"

void* leeEntero(ifstream &arch) {
    int *dato,d;
    arch>>d;
    if (arch.eof()) return nullptr;
    dato = new int(d);
    *dato = d;
    return dato;
}
int compararEnteros(const void* a, const void* b) {
    int *aI = (int*) a, *bI = (int*) b ;
    return *aI - *bI;
}
void imprimirEntero(ofstream &arch,void *dato) {
    int *aI = (int*) dato;
    arch<<setw(5)<<*aI;
}
