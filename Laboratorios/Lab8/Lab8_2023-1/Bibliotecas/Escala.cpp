#include <iostream>
#include <fstream>

using namespace std;
#include "Escala.h"

Escala::Escala() {
    inicializar();
}

Escala::Escala(int cod, double prec) {
    inicializar();
    codigo = cod;
    precio = prec;
}

Escala::Escala(const Escala &esc) {
    inicializar();
    *this = esc;
}

Escala::~Escala() {
    eliminar();
}

void Escala::eliminar() {
    codigo = 0;
    precio = 0;
}

void Escala::operator=(const Escala &esc) {
    inicializar();
    codigo = esc.get_codigo();
    precio = esc.get_precio();
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
    double preci;
    int cod;
    arch>>cod;
    if (arch.eof()) return;
    arch.get();
    arch>>preci;
    set_codigo(cod);
    set_precio(preci);
}
