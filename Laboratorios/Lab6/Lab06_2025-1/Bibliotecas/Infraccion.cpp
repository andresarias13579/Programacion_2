#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Infraccion.h"

Infraccion::Infraccion() {
    inicializar();
}

Infraccion::Infraccion(const Infraccion & infraccion) {
    inicializar();
    *this = infraccion;
}

Infraccion::~Infraccion() {
    liberar();
}

void Infraccion::operator =(const Infraccion & infraccion) {
    multa = infraccion.get_multa();
    codigo = infraccion.get_codigo();
    char descripcion[200],gravedad[200];
    infraccion.get_descripcion(descripcion);
    infraccion.get_gravedad(gravedad);
    set_descripcion(descripcion);
    set_gravedad(gravedad);
}

void Infraccion::liberar() {
    if (descripcion) delete [] descripcion;
    if (gravedad) delete [] gravedad;
}

void Infraccion::inicializar() {
    gravedad = nullptr;
    descripcion = nullptr;
}

int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const int codigo) {
    this->codigo = codigo;
}

char * Infraccion::get_descripcion(char * desc) const {
    if (descripcion == nullptr) desc[0] = 0;
    else strcpy(desc, descripcion);
    return desc;
}

void Infraccion::set_descripcion(char * const desc) {
    if (descripcion) delete [] descripcion;
    descripcion = new char[strlen(desc)+1];
    strcpy(descripcion,desc);
}

char * Infraccion::get_gravedad(char * grav) const {
    if (gravedad == nullptr) grav[0] = 0;
    else strcpy(grav, gravedad);
    return grav;
}

void Infraccion::set_gravedad(char * const grav) {
    if (gravedad) delete [] gravedad;
    gravedad = new char[strlen(grav)+1];
    strcpy(gravedad,grav);
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(const double multa) {
    this->multa = multa;
}

void Infraccion::leeArch(ifstream &arch) {
    int codInfra;
    double multita;
    char gravedad[200],descripcion[200],c;
    arch>>codInfra;
    if (arch.eof()) return;
    arch.get();
    arch>>multita>>c;
    arch.getline(gravedad,200,',');
    arch.getline(descripcion,200,'\n');
    set_codigo(codInfra);
    set_multa(multita);
    set_gravedad(gravedad);
    set_descripcion(descripcion);
}

void Infraccion::imprimir(ofstream &arch) const {
    arch<<fixed<<setprecision(2);
    arch<<setw(10)<<codigo<<setw(10)<<multa<<setw(4)<<" "
        <<left<<setw(20)<<gravedad<<setw(100)<<descripcion<<right<<endl;
}

void operator >> (ifstream &arch, Infraccion & origen) {
    origen.leeArch(arch);
}
void operator << (ofstream &arch, const Infraccion & origen) {
    origen.imprimir(arch);
}