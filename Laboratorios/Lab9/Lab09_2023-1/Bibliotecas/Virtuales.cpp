#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Virtuales.h"

Virtuales::Virtuales() {
    inicializar();
}
Virtuales::Virtuales(const Virtuales &vir) {
    inicializar();
    *this = vir;
}
Virtuales::~Virtuales() {
    eliminar();
}
void Virtuales::eliminar() {
    if (licencia) delete[] licencia;
    total = 0;
}
void Virtuales::operator=(const Virtuales &vir) {
    char lice[50];
    total = 0;
    vir.get_licencia(lice);
    set_licencia(lice);
    Alumno::operator=(vir);
}
void Virtuales::inicializar() {
    total = 0;
    licencia = nullptr;
}

char * Virtuales::get_licencia(char * lice) const {
    if (licencia == nullptr) lice[0]=0;
    else strcpy(lice,licencia);
    return lice;
}
void Virtuales::set_licencia(const char * lice) {
    if (licencia) delete[] licencia;
    licencia = new char[strlen(lice)+1];
    strcpy(licencia,lice);
}
double Virtuales::get_total() const {
    return total;
}

void Virtuales::set_total(const double total) {
    this->total = total;
}

void Virtuales::leeDatos(ifstream &arch) {
    char lice[50];
    Alumno::leeDatos(arch);
    arch.getline(lice,50,'\n');
    set_licencia(lice);
}

void Virtuales::imprimeAlumno(ofstream &arch) {
    Alumno::imprimeAlumno(arch);
    arch<<setw(10)<<licencia<<endl;
}

