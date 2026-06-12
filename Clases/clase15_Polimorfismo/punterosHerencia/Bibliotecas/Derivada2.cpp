#include <iostream>

using namespace std;
#include "Derivada2.h"

Derivada2::Derivada2() {
    cout << "Derivada2 constructor" << endl;
}

Derivada2::~Derivada2() {
    cout << "Derivada2 destructor" << endl;
}

int Derivada2::get_d2() const {
    return d2;
}

void Derivada2::set_d2(const int d2) {
    this->d2 = d2;
}

void Derivada2::mostrar() const {
    cout<<"Estamos en la clase Derivada2"<<endl;
    cout<<"B = "<<get_b()<<endl;
    cout<<"D2= "<<d2<<endl;
}
