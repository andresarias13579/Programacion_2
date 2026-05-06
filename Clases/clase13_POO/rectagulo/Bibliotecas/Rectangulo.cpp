#include <iomanip>
#include <iostream>
using namespace std;
#include "Rectangulo.h"

#include <iostream>

void Rectangulo::asignarBase(double b) {
    base = b;
}

void Rectangulo::asignarAltura(double h) {
    altura = h;
}

double Rectangulo::entregarBase() {
    return base;
}

double Rectangulo::entregarAltura() {
    return altura;
}

void Rectangulo::asignarAtributos(double b, double h) {
    base = b;
    altura = h;
}

void Rectangulo::leeDatos() {
    cout<<"Base: ";
    cin>>base;
    cout<<"Altura: ";
    cin>>altura;
}
double Rectangulo::area() {
    return base * altura;
}
double Rectangulo::perimetro() {
    return 2*(base + altura);
}
void Rectangulo::mostrarResultados() {
    cout<<fixed<<setprecision(2);
    cout<<"Rectangulo base: "<<base<<endl;
    cout<<"Rectangulo altura: "<<altura<<endl;
    cout<<"Rectangulo perimetro: "<<perimetro()<<endl;
    cout<<"Rectangulo area: "<<area()<<endl;
}
