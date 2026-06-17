#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    inicializar();
}
Presencial::Presencial(const Presencial &pre) {
    inicializar();
    *this = pre;
}
void Presencial::operator=(const Presencial &pre) {
    total = pre.total;
    recargo = pre.recargo;
    Alumno::operator=(pre);
}
Presencial::~Presencial() {
    eliminar();
}

void Presencial::eliminar() {
    total = 0;
    recargo = 0;
}

void Presencial::inicializar() {
    total = 0;
    recargo = 0;
}

double Presencial::get_recargo() const {
    return recargo;
}

void Presencial::set_recargo(const double recargo) {
    this->recargo = recargo;
}

double Presencial::get_total() const {
    return total;
}

void Presencial::set_total(const double total) {
    this->total = total;
}

void Presencial::leeDatos(ifstream &arch) {
    Alumno::leeDatos(arch);
    arch>>recargo;
    arch.get();
}

void Presencial::imprimeAlumno(ofstream &arch) {
    Alumno::imprimeAlumno(arch);
    arch<<setw(20)<<" "<<total<<endl;
}

