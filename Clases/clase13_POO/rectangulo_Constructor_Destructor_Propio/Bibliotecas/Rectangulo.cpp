#include <cstring>
#include <iostream>
using namespace std;
#include "Rectangulo.h"

Rectangulo::Rectangulo() {
    inicializar();
    cout<<"Estoy en el constructor por defecto"<<endl;
}

Rectangulo::Rectangulo(double b, double h, char *nomb) {
    inicializar();
    base = b;
    altura = h;
    set_nombre(nomb);
    cout<<"Estoy el constructor con parametros"<<endl;
}

Rectangulo::~Rectangulo() {
    liberarEspacios();
    cout<<"Estoy en el destructor"<<endl;
}

void Rectangulo::liberarEspacios() {
    if (nombre) delete[] nombre;
}

void Rectangulo::inicializar() {
    nombre = nullptr;
}

double Rectangulo::get_base() const {
    return base;
}

void Rectangulo::set_base(const double base) {
    this->base = base;
}

double Rectangulo::get_altura() const {
    return altura;
}

void Rectangulo::set_altura(const double altura) {
    this->altura = altura;
}

char * Rectangulo::get_nombre(char * nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
    return nomb;
}

void Rectangulo::set_nombre(const char * nomb) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Rectangulo::mostrar() const {
    cout<<"base: "<<base<<endl;
    cout<<"altura: "<<altura<<endl;
    char *nomb = new char[60];
    // get_nombre(nomb);
    cout<<"nombre: "<<get_nombre(nomb)<<endl;
}


