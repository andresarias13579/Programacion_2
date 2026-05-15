#include <iostream>
using namespace std;
#include "Rectangulo.h"


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

void Rectangulo::mostrar() const {
    cout<<"base: "<<base<<endl;
    cout<<"altura: "<<altura<<endl;
}
