#include <cstring>
#include <iostream>

using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    inicializar();
}

Alumno::Alumno(const int codigo, const char *nombre, const int escala, double total) {
    inicializar();
    set_codigo(codigo);
    set_nombre(nombre);
    set_escala(escala);
    set_total(total);
}

Alumno::Alumno(const Alumno &alum) {
    inicializar();
    *this = alum;
}

Alumno::~Alumno() {
    eliminar();
}

void Alumno::eliminar() {
    if (nombre) delete [] nombre;
}

void Alumno::operator=(const Alumno &alum) {
    char nomb[100];
    codigo = alum.get_codigo();
    escala = alum.get_escala();
    total = alum.get_total();
    alum.get_nombre(nomb);
    set_nombre(nomb);
}

void Alumno::inicializar() {
    nombre = nullptr;
    total = 0;
    codigo = 0;
}

int Alumno::get_codigo() const {
    return codigo;
}

void Alumno::set_codigo(const int codigo) {
    this->codigo = codigo;
}

char * Alumno::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
    return nomb;
}

void Alumno::set_nombre(const char *  nomb) {
    if (nombre) delete [] nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

int Alumno::get_escala() const {
    return escala;
}

void Alumno::set_escala(const int escala) {
    this->escala = escala;
}

double Alumno::get_total() const {
    return total;
}

void Alumno::set_total(const double total) {
    this->total = total;
}
