#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Semiprecensial.h"

Semiprecensial::Semiprecensial() {
    inicializar();
}

Semiprecensial::Semiprecensial(const Semiprecensial &semi) {
    inicializar();
    *this = semi;
}
Semiprecensial::~Semiprecensial() {
    eliminar();
}
void Semiprecensial::eliminar() {
    total = 0;
    descuento = 0;
}

void Semiprecensial::operator=(const Semiprecensial &semi) {
    total = semi.total;
    descuento = semi.descuento;
    Alumno::operator=(semi);
}

void Semiprecensial::inicializar() {
    total = 0;
    descuento = 0;
}

double Semiprecensial::get_descuento() const {
    return descuento;
}

void Semiprecensial::set_descuento(const double descuento) {
    this->descuento = descuento;
}

double Semiprecensial::get_total() const {
    return total;
}

void Semiprecensial::set_total(const double total) {
    this->total = total;
}

void Semiprecensial::leeDatos(ifstream &arch) {
    Alumno::leeDatos(arch);
    arch>>descuento;
    arch.get();
}

void Semiprecensial::imprimeAlumno(ofstream &arch) {
    Alumno::imprimeAlumno(arch);
    arch<<setw(20)<<descuento<<endl;
}

