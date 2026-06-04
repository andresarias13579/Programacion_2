#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    inicializa();
}

Semipresencial::Semipresencial(double descuento, double total, int codigo, const char *nombre,
    int escala, double tot) : Alumno(codigo, nombre, escala, tot) {
    inicializa();
    set_descuento(descuento);
    set_total(total);
}

Semipresencial::Semipresencial(const Semipresencial &semi) {
    inicializa();
    *this = semi;
}

void Semipresencial::operator=(const Semipresencial &semi) {
    total = semi.get_total();
    descuento = semi.get_descuento();
    Alumno::operator=(semi);
}

Semipresencial::~Semipresencial() {
    eliminar();
}

void Semipresencial::eliminar() {
    total = 0;
    descuento = 0;
}

void Semipresencial::inicializa() {
    total = 0;
}

double Semipresencial::get_descuento() const {
    return descuento;
}

void Semipresencial::set_descuento(const double descuento) {
    this->descuento = descuento;
}

double Semipresencial::get_total() const {
    return total;
}

void Semipresencial::set_total(const double total) {
    this->total = total;
}

void Semipresencial::leeSemipresencial(ifstream &arch) {
    int cod,esc;
    char nombre[100],c;
    double desc;
    arch>>cod>>c;
    arch.getline(nombre,100,',');
    arch>>esc>>c>>desc;
    set_descuento(desc);
    set_codigo(cod);
    set_escala(esc);
    set_nombre(nombre);
}

void Semipresencial::actualizar(double monto) {
    set_total(monto*(1-descuento/100));
}

void Semipresencial::mostrar(ofstream &arch) {
    char nombre[100];
    arch<<get_codigo()<<setw(10)<<" "<<left<<setw(35)<<get_nombre(nombre)<<right
        <<setw(5)<<get_escala()<<setw(25)<<get_total()<<endl;
}
