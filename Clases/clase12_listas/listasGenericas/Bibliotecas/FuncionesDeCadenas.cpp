#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesDeCadenas.h"

void* leeCadena(ifstream &arch) {
    char cadena[60],*cad;
    arch.getline(cadena,60);
    if (arch.eof()) return nullptr;
    cad= new char[strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
}
int compararCadenas(const void* a, const void* b) {
    char *aI = (char*) a, *bI = (char*) b ;
    return strcmp(aI,bI);
}
void imprimirCadena(ofstream &arch,void *dato) {
    char *aI = (char*) dato;
    arch<<aI<<endl;
}
