#include <cstring>
#include <iostream>
#include <iomanip>

#define PI 3.141592

using namespace std;
#include "Circulo.h"

Circulo::Circulo() {
    inicializar();
}

Circulo::Circulo(double rad,const char *nomb) {
    inicializar();
    set_radio(rad);
    set_nombre(nomb);
}

Circulo::Circulo(const Circulo &cir) {
    inicializar();
    *this = cir;
}

Circulo::~Circulo() {
    eliminar();
}

void Circulo::eliminar() {
    if (nombre) delete [] nombre;
}

void Circulo::operator=(const Circulo &cir) {
    set_nombre(cir.nombre);
    set_radio(cir.radio);
}

void Circulo::inicializar() {
    nombre = nullptr;
}

double Circulo::get_radio() const {
    return radio;
}

void Circulo::set_radio(const double radio) {
    this->radio = radio;
}

char * Circulo::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = '\0';
    else strcpy(nomb, nombre);
    return nomb;
}

void Circulo::set_nombre(const char* nomb) {
    if (nombre) delete [] nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

double Circulo::area() const{
    return PI*radio*radio;
}

double Circulo::circunferencia() const {
    return PI*radio*2;
}

void Circulo::mostrarResultados() {
    cout.precision(2);
    cout<<fixed;
    cout<<"Nombre: "<<setw(10)<<nombre<<endl;
    cout<<"Radio: "<<setw(10)<<radio<<endl;
    cout<<"Area: "<<setw(10)<<area()<<endl;
    cout<<"Circunferencia: "<<setw(10)<<circunferencia()<<endl;

}
