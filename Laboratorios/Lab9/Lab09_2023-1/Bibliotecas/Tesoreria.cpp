#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
#include "Tesoreria.h"

void Tesoreria::cargaescalas(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    int numEscalas = 0;
    while (true) {
        lescala[numEscalas].leeEscala(arch);
        if (arch.eof()) break;
        numEscalas++;
    }
}

void Tesoreria::cargaalumnos(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    int numAlum = 0;
    char tipo;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        lboleta[numAlum].asignaMemoria(tipo);
        lboleta[numAlum].lee(arch);
        numAlum++;
    }
}

void Tesoreria::imprimeboleta(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    arch<<"Codigo               Nombre                             Escala                  Cred           Licencia                Total"<<endl;
    arch<<setfill('=')<<setw(200)<<"="<<setfill(' ')<<endl;
    for (int i = 0; lboleta[i].hayDato();i++) {
        lboleta[i].imprime(arch);
    }
}
