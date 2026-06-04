#include <cstring>
#include <iostream>
#include <iomanip>

// #define PI 3.141592

using namespace std;
using namespace std;
#include "Cilindro.h"

Cilindro::Cilindro() {
    inicializar();
}

Cilindro::Cilindro(double altura, double rad, const char *nomb) {
    inicializar();
    Circulo(rad,nomb);
    set_altura(altura);
}

Cilindro::Cilindro(const Cilindro &cili) {
    inicializar();
    *this = cili;
}

void Cilindro::operator=(const Cilindro &cili) {
    char aux[100];
    inicializar();
    set_radio(cili.get_radio());
    cili.get_nombre(aux);
    set_nombre(aux);
    altura = cili.get_altura();
}

void Cilindro::inicializar() {
    altura = 0;
}

double Cilindro::get_altura() const {
    return altura;
}

void Cilindro::set_altura(const double altura) {
    this->altura = altura;
}

double Cilindro::volumen() {
    return Circulo::area()*altura;
}

double Cilindro::area() {
    return circunferencia()*altura + 2*Circulo::area();
}

void Cilindro::mostrarResultados() {
    char aux[100];
    get_nombre(aux);
    cout<<"Nombre: "<<setw(10)<<aux<<endl;
    cout<<"Radio: "<<setw(10)<<get_radio()<<endl;
    cout<<"Altura: "<<setw(10)<<altura<<endl;
    cout<<"Area: de la base"<<setw(10)<<Circulo::area()<<endl;
    cout<<"Circunferencia: "<<setw(10)<<circunferencia()<<endl;
    cout<<"Volumen: "<<setw(10)<<volumen()<<endl;
    cout<<"Area de superficie: "<<setw(10)<<area()<<endl;
}
