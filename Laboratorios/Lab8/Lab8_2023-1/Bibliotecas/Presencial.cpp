#include <iostream>
#include <fstream>


using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    inicializar();
}

Presencial::Presencial(double recar, double tota, int codigo, const char *nombre,int escala,
    double tot) :
    Alumno(codigo, nombre, escala, tot){
    inicializar();
    recargo = recar;
    total = tota;
}

Presencial::Presencial(const Presencial &pre) {
    inicializar();
    *this = pre;
}

void Presencial::operator=(const Presencial &pre) {
    char nombre[100];
    recargo = pre.get_recargo();
    total = pre.get_total();
    Alumno::operator=(pre);
}

Presencial::~Presencial() {
    eliminar();
}

void Presencial::eliminar() {
    total = 0;
    recargo = 0;
}

void Presencial::inicializar() {
    total = 0;
}

double Presencial::get_recargo() const {
    return recargo;
}

void Presencial::set_recargo(const double recargo) {
    this->recargo = recargo;
}

double Presencial::get_total() const {
    return total;
}

void Presencial::set_total(const double total) {
    this->total = total;
}

void Presencial::leePresencial(ifstream &arch) {
    int cod,esc;
    char nombre[100],c;
    double recar;
    arch>>cod>>c;
    arch.getline(nombre,100,',');
    arch>>esc>>c>>recar;
    set_recargo(recar);
    set_codigo(cod);
    set_escala(esc);
    set_nombre(nombre);
}

void Presencial::actualizar(double monto) {
    set_total(monto*(1+recargo/100));
}
