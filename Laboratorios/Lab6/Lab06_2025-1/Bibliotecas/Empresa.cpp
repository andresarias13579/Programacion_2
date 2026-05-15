#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Empresa.h"

Empresa::Empresa() {
    inicializar();
}

Empresa::~Empresa() {
    liberar();
}

void Empresa::liberar() {
    if (nombre) delete [] nombre;
    for (int i = 0; i < numPlacas; i++) {
        if (placas[i]) delete [] placas[i];
    }
}

void Empresa::inicializar() {
    nombre = nullptr;
    numPlacas = 0;
    numMultas = 0;
    for (int i = 0; i < 10; i++) placas[i] = nullptr;
}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(const int dni) {
    this->dni = dni;
}

char * Empresa::get_nombre(char * nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
    return nomb;
}

void Empresa::set_nombre(char * const nomb) {
    if (nombre) delete [] nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(const int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}

void Empresa::set_num_multas(const int num_multas) {
    numMultas = num_multas;
}

void Empresa::setPlacaI(const char *plac, int i) {
    if (placas[i]) delete [] placas[i];
    placas[i] = new char[strlen(plac) + 1];
    strcpy(placas[i], plac);
}

void Empresa::getPlacaI(char *plac, int i) {
    if (placas[i] == nullptr) plac[0] = 0;
    else strcpy(plac, placas[i]);
}

void Empresa::leeArch(ifstream &arch) {
    int dni;
    char nombre[100];
    char plac[9],c;
    arch >> dni;
    if (arch.eof()) return;
    arch>>c;
    arch.getline(nombre,100,',');
    set_dni(dni);
    set_nombre(nombre);
    while (true) {
        arch.get(plac,9);
        setPlacaI(plac,numPlacas);
        numPlacas++;
        if (arch.get() == '\n') break;
    }
}

void Empresa::operator+=(Multa &multa) {
    multas[numMultas] = multa;
    numMultas++;
}

void Empresa::imprimir(ofstream &arch) const {
    arch<<fixed<<setprecision(2);
    arch<<setw(12)<<dni<<setw(4)<<" "<<setw(35)<<nombre<<setw(12);
    for (int i = 0; i < numPlacas; i++) {
        arch<<placas[i]<<" ";
    }
    arch<<right<<endl;
    arch<<setw(17)<<"Placa"<<setw(19)<<"Fecha Inf"<<setw(11)<<"Cod Inf"
        <<setw(8)<<"Multa"<<setw(18)<<"Fecha Pago"<<endl;
    for (int i = 0; i < numMultas; i++) {
        arch<<multas[i];
    }
}

void operator>>(ifstream &arch, Empresa &origen) {
    origen.leeArch(arch);
}
void operator <<(ofstream &arch, const Empresa &origen) {
    origen.imprimir(arch);
}