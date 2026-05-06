#include <cstring>
#include <iostream>
#include <cstring>
using namespace std;
#include "Rectangulo.h"

Rectangulo::Rectangulo() {
    inicializar();
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
void Rectangulo::mostrar() const{
    cout<<"base = "<<base<<endl;
    cout<<"altura = "<<altura<<endl;
}

void Rectangulo::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    strcpy(nomb,nombre);
}

void Rectangulo::set_nombre(char * nomb) {
    if (nombre != nullptr) delete[] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

