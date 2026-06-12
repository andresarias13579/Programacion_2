#include <iostream>

using namespace std;
#include "Derivada1.h"

Derivada1::Derivada1() {
    cout << "Constructor de la derivada 1" << endl;
}

Derivada1::~Derivada1() {
    cout << "Destructor de la derivada 1" << endl;
}

int Derivada1::get_d() const {
    return d;
}

void Derivada1::set_d(const int d) {
    this->d = d;
}

void Derivada1::mostrar() const {
    cout << "Estamos en la clase derivada 1"<<endl;
    cout << "B = "<<get_b()<<endl;
    cout << "D = "<<d<<endl;
}
