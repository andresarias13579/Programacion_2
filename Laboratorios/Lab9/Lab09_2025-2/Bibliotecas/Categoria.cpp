#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Categoria.h"

Categoria::Categoria() {
}

Categoria::Categoria(const Categoria &cat) {
    *this = cat;
}
void Categoria::operator=(const Categoria &cat) {
    nombrea = cat.nombrea;
    descripcion = cat.descripcion;
    codigo = cat.codigo;
}

string Categoria::get_codigo() const {
    return codigo;
}

void Categoria::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Categoria::get_nombrea() const {
    return nombrea;
}

void Categoria::set_nombrea(const string &nombrea) {
    this->nombrea = nombrea;
}

string Categoria::get_descripcion() const {
    return descripcion;
}

void Categoria::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

void Categoria::lee(ifstream &arch) {
    getline(arch, codigo,',');
    if(arch.eof()) return;
    getline(arch, nombrea,',');
    getline(arch, descripcion,'\n');
}

void Categoria::imprime(ofstream &arch) const {
    arch<<"CATEGORIA:"<<endl;
    arch<<"CODIGO: "<<codigo<<endl;
    arch<<"NOMBREA: "<<nombrea<<endl;
    arch<<"DESCRIPTION: "<<descripcion<<endl;
}

bool Categoria::operator<(const Categoria &cat) {
    return codigo < cat.codigo;
}

void operator>>(ifstream &arch, Categoria &eti) {
    eti.lee(arch);
}
void operator<<(ofstream &arch, Categoria &eti) {
    eti.imprime(arch);
}
