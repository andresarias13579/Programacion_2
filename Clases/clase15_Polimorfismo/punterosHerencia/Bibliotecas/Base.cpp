#include <iostream>

using namespace std;
#include "Base.h"

Base::Base() {
    cout<<"Constructor de la clase base"<<endl;
}

Base::~Base() {
    cout<<"Destructor de la clase base"<<endl;
}

int Base::get_b() const {
    return b;
}

void Base::set_b(const int b) {
    this->b = b;
}

void Base::mostrar() const {
    cout<<"Estamos en la clase Base"<<endl;
    cout<<"B = "<<b<<endl;
}
