#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    inicializar();
}

Alumno::Alumno(const Alumno &alum) {
    *this = alum;
}

Alumno::~Alumno() {
    eliminar();
}

void Alumno::eliminar() {
    if (nombre) delete [] nombre;
    total = 0;
}

void Alumno::operator=(const Alumno &alum) {
    char nombre[50];
    alum.get_nombre(nombre);
    set_nombre(nombre);
    set_escala(alum.get_escala());
    set_creditos(alum.get_creditos());
    set_total(alum.get_total());
    set_codigo(alum.get_codigo());
}

void Alumno::inicializar() {
    nombre = nullptr;
    codigo = 0;
    escala = 0;
    total = 0;
    creditos = 0;
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

void Alumno::set_nombre(const char * nomb) {
    if (nombre) delete [] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

int Alumno::get_escala() const {
    return escala;
}

void Alumno::set_escala(const int escala) {
    this->escala = escala;
}

double Alumno::get_creditos() const {
    return creditos;
}

void Alumno::set_creditos(const double creditos) {
    this->creditos = creditos;
}

double Alumno::get_total() const {
    return total;
}


void Alumno::set_total(const double total) {
    this->total = total;
}

void Alumno::leeDatos(ifstream &arch) {
    char nombAux[60], c;
    int codAux, escAux;
    double credAux;

    arch >> codAux >> c;
    if (arch.eof()) return;

    arch.getline(nombAux, 60, ',');
    arch >> escAux >> c >> credAux >> c;

    // Guardar los datos reales en el objeto
    set_codigo(codAux);
    set_nombre(nombAux);
    set_escala(escAux);
    set_creditos(credAux);
}

void Alumno::imprimeAlumno(ofstream &arch) {
    arch<<codigo<<setw(10)<<" "<<left<<setw(50)<<nombre<<right<<setw(5)<<escala<<setw(10)<<creditos;
}
