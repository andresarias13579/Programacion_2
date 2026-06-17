#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
#include "Escala.h"

Escala::Escala() {
    inicializar();
}

Escala::Escala(const Escala &esc) {
    *this = esc;
}
Escala::~Escala() {
    eliminar();
}

void Escala::eliminar() {
    precio = 0;
    codigo = 0;
}

void Escala::operator=(const Escala &esc) {
    precio = esc.precio;
    codigo = esc.codigo;
}

void Escala::inicializar() {
    codigo = 0;
    precio = 0;
}

int Escala::get_codigo() const {
    return codigo;
}

void Escala::set_codigo(const int codigo) {
    this->codigo = codigo;
}

double Escala::get_precio() const {
    return precio;
}

void Escala::set_precio(const double precio) {
    this->precio = precio;
}

void Escala::leeEscala(ifstream &arch) {
    int cod;
    double prec;
    arch >> cod ;
    if (arch.eof()) return;
    arch.get();
    arch >> prec;
}


