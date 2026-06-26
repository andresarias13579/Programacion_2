#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Etiqueta.h"

Etiqueta::Etiqueta() {
    inicializa();
}

Etiqueta::Etiqueta(const Etiqueta &eti) {
    inicializa();
    *this = eti;
}
Etiqueta::~Etiqueta() {
    eliminar();
}
void Etiqueta::inicializa() {
}

void Etiqueta::operator=(const Etiqueta &eti) {
    codigo = eti.codigo;
    nombre = eti.nombre;
}
void Etiqueta::eliminar() {
}

string Etiqueta::get_codigo() const {
    return codigo;
}

void Etiqueta::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Etiqueta::get_nombre() const {
    return nombre;
}

void Etiqueta::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

void Etiqueta::lee(ifstream &arch)  {
    getline(arch, codigo,',');
    if (arch.eof()) return;
    getline(arch, nombre,'\n');
}

void Etiqueta::imprime(ofstream &arch) const {
    arch<<"     CODIGO: "<<codigo<<setw(10)<<"NOMBRE: "<<nombre<<endl;
}

void operator >> (ifstream &arch,  Etiqueta &eti) {
    eti.lee(arch);
}
void operator << (ofstream &arch, const Etiqueta &eti) {
    eti.imprime(arch);
}