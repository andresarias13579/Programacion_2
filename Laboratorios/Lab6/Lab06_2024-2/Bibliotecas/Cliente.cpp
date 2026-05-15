#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Cliente.h"

Cliente::Cliente() {
    inicializar();
}

Cliente::Cliente(const Cliente &cliente) {
    inicializar();
    *this = cliente;
}

Cliente::~Cliente() {
    eliminar();
}

void Cliente::eliminar() {
    if (nombre) delete [] nombre;
    if (distrito) delete [] distrito;
}

void Cliente::operator=(const Cliente &cliente) {
    char nombre[100],distrito[100];
    dni = cliente.get_dni();
    cliente.get_nombre(nombre);
    set_nombre(nombre);
    cliente.get_distrito(distrito);
    set_distrito(distrito);
    descuento = cliente.get_descuento();
    totalPagado = cliente.get_total_pagado();
}

void Cliente::inicializar() {
    nombre = nullptr;
    distrito = nullptr;
    totalPagado = 0;
}

int Cliente::get_dni() const {
    return dni;
}

void Cliente::set_dni(const int dni) {
    this->dni = dni;
}

char * Cliente::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
    return nomb;
}

void Cliente::set_nombre(char * const nomb) {
    if (nombre) delete [] nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

char * Cliente::get_distrito(char *dist) const {
    if (distrito == nullptr) dist[0] = 0;
    else strcpy(dist, distrito);
    return dist;
}

void Cliente::set_distrito(char * const dist) {
    if (distrito) delete [] distrito;
    distrito = new char[strlen(dist) + 1];
    strcpy(distrito, dist);
}

double Cliente::get_descuento() const {
    return descuento;
}

void Cliente::set_descuento(const double descuento) {
    this->descuento = descuento;
}

double Cliente::get_total_pagado() const {
    return totalPagado;
}

void Cliente::set_total_pagado(const double total_pagado) {
    totalPagado = total_pagado;
}

void Cliente::imprimir(ofstream &arch) const {
    arch<<fixed<<setprecision(2);
    arch<<dni<<setw(10)<<" "<<left<<setw(40)<<nombre<<setw(30)<<distrito<<right<<setw(10)<<descuento<<"%"<<setw(12)<<totalPagado<<endl;
}

void operator >> (ifstream &arch, Cliente &origen) {
    int dni;
    char nombre[100];
    char distrito[100],descontar,c;
    double descuento;
    arch>>dni;
    if (arch.eof()) return;
    arch>>c;
    arch.getline(nombre,100,',');
    arch.getline(distrito,100,',');
    arch>>descontar;
    if (descontar == 'S') {
        arch>>c>>descuento>>c;
        arch.get();
    }else descuento = 0;
    origen.set_dni(dni);
    origen.set_nombre(nombre);
    origen.set_distrito(distrito);
    origen.set_descuento(descuento);
}
void operator << (ofstream &arch, const Cliente &origen) {
    origen.imprimir(arch);
}
