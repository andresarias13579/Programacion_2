#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Metrica.h"

Metrica::Metrica() {
    inicializar();
}

Metrica::Metrica(const Metrica &metrica) {
    inicializar();
    *this = metrica;
}

Metrica::~Metrica() {
    eliminar();
}

void Metrica::inicializar() {
    descripcion = nullptr;
    estado = false;
    id = 0;
    fecha_calculo = 0;
    fecha_expiracion = 0;
}

void Metrica::eliminar() {
    if (descripcion != nullptr) delete [] descripcion;
}

void Metrica::operator=(const Metrica &met) {
    char desc[100];
    met.get_descripcion(desc);
    set_descripcion(desc);
    id = met.get_id();
    fecha_calculo = met.get_fecha_calculo();
    fecha_expiracion = met.get_fecha_expiracion();
    estado = met.get_estado();
}

int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(const int id) {
    this->id = id;
}

char * Metrica::get_descripcion(char * desc) const {
    if (descripcion == nullptr) desc[0] = 0;
    else strcpy(desc, descripcion);
    return desc;
}

void Metrica::set_descripcion(const char * desc) {
    if (descripcion) delete [] descripcion;
    descripcion = new char[strlen(desc)+1];
    strcpy(descripcion, desc);
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(const int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}

void Metrica::set_fecha_expiracion(const int fecha_expiracion) {
    this->fecha_expiracion = fecha_expiracion;
}

bool Metrica::get_estado() const {
    return estado;
}

void Metrica::set_estado(const bool estado) {
    this->estado = estado;
}

void Metrica::leer(ifstream &arch) {
    char desc[100],c;
    int idStream,fecha_cal,fecha_exp;
    arch >> idStream;
    if (arch.eof()) return;
    arch.get();
    arch.getline(desc,100,',');
    leeFecha(arch,fecha_cal);
    leeFecha(arch,fecha_exp);
    set_descripcion(desc);
    set_fecha_calculo(fecha_cal);
    set_fecha_expiracion(fecha_exp);
    set_id(idStream);
    if (20251114 > fecha_exp) {
        estado = false;
    } else {
        estado = true;
    }
}

void Metrica::leeFecha(ifstream &arch, int &fecha) {
    int dd,mm,aa;
    char c;
    arch >> aa>>c>>mm>>c>>dd>>c;
    fecha  = aa*10000 + mm*100 + dd;
}

void Metrica::imprimir(ofstream &arch) const {
    arch<<setfill('0')<<setw(4)<<id<<setfill(' ')<<setw(2)<<" "<<left<<setw(25)<<descripcion<<right
        <<setw(12)<<fecha_calculo<<setw(12)<<fecha_expiracion;
    if (estado) arch<<setw(2)<<" "<<left<<setw(12)<<"ACTIVA";
    else arch<<setw(2)<<" "<<left<<setw(12)<<"INACTIVA";
    arch<<right;
}
