#include <cstring>
#include <iostream>
#include <fstream>

#include "Alumno.h"

using namespace std;
#include "Virtual.h"

Virtual::Virtual() {
    inicializar();
}

Virtual::Virtual(const char *licencia, double total, int cod,
    const char *nomb, int escal, double tot)
    : Alumno(cod,nomb,escal,tot) {
    inicializar();
    set_licencia(licencia);
    set_total(total);
}

Virtual::Virtual(const Virtual &vir) {
    inicializar();
    *this = vir;
}

void Virtual::operator=(const Virtual &vir) {
    char lice[100];
    set_nombre(vir.get_licencia(lice));
    set_total(vir.get_total());
    Alumno::operator=(vir);
}

Virtual::~Virtual() {
    eliminar();
}

void Virtual::eliminar() {
    if (licencia) delete[] licencia;
    total = 0;
}

void Virtual::inicializar() {
    licencia = nullptr;
    total = 0;
}

char * Virtual::get_licencia(char *lice) const {
    if (licencia == nullptr) lice[0] = 0;
    else strcpy(lice,licencia);
    return lice;
}

void Virtual::set_licencia(const char * lice) {
    if (licencia) delete[] licencia;
    licencia = new char[strlen(lice)+1];
    strcpy(licencia,lice);
}

double Virtual::get_total() const {
    return total;
}

void Virtual::set_total(const double total) {
    this->total = total;
}

void Virtual::leeVirtual(ifstream &arch) {
    int cod,esc;
    char nombre[100],c,lice[100];
    arch>>cod>>c;
    arch.getline(nombre,100,',');
    arch>>esc>>c;
    arch.getline(lice,100,'\n');
    set_licencia(lice);
    set_codigo(cod);
    set_escala(esc);
    set_nombre(nombre);
}

void Virtual::actualizar(double monto) {
    set_total(monto + 100);
}
