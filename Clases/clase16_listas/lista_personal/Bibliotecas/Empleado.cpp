#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Empleado.h"

Empleado::Empleado() {
    inicializar();
}

Empleado::Empleado(const Empleado &emp) {
    inicializar();
    *this = emp;
}

Empleado::~Empleado() {
    eliminar();
}

void Empleado::inicializar() {
    nombre = nullptr;
    codigo = 0;
    sueldo = 0;
}

void Empleado::eliminar() {
    if (nombre) delete [] nombre;
}

void Empleado::operator=(const Empleado &emp) {
    char nomb[100];
    emp.get_nombre(nomb);
    set_nombre(nomb);
    sueldo = emp.get_sueldo();
    codigo = emp.get_codigo();
}

int Empleado::get_codigo() const {
    return codigo;
}

void Empleado::set_codigo(const int codigo) {
    this->codigo = codigo;
}

char * Empleado::get_nombre(char * nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
    return nomb;
}

void Empleado::set_nombre(const char * nomb) {
    if (nombre) delete [] nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

double Empleado::get_sueldo() const {
    return sueldo;
}

void Empleado::set_sueldo(const double sueldo) {
    this->sueldo = sueldo;
}

void Empleado::lee(ifstream &arch){
    char nomb[100];
    arch>>codigo;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nomb, 100,',');
    set_nombre(nomb);
    arch>>sueldo;
}

bool Empleado::operator>(const Empleado &emp) {
    if (codigo > emp.get_codigo()) return true;
    else return false;
}

void Empleado::imprime(ofstream &arch) const{
    arch<<codigo<<setw(10)<<" "<<left<<setw(30)<<nombre<<right<<setw(10)<<sueldo<<endl;
}

void operator >> (ifstream &arch,Empleado &dato) {
    dato.lee(arch);
}

void operator << (ofstream &arch,const Empleado &dato) {
    dato.imprime(arch);
}
