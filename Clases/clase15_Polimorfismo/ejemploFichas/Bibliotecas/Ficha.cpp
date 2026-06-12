#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Ficha.h"

Ficha::Ficha() {
    inicializa();
}

Ficha::Ficha(const Ficha &fich) {
    inicializa();
    *this = fich;
}

Ficha::~Ficha() {
    elimina();
}

void Ficha::elimina() {
    if (id) delete [] id;
}

void Ficha::operator =(const Ficha &fich) {
    char id[100];
    fich.get_id(id);
    set_id(id);
    fila = fich.get_fila();
    columna = fich.get_columna();
}

void Ficha::inicializa() {
    id = nullptr;
    fila = 0;
    columna = 0;
}

char * Ficha::get_id(char * ID) const {
    if (id == nullptr) ID[0] = 0;
    else strcpy(ID, id);
    return ID;
}

void Ficha::set_id(const char * ID) {
    if (id) delete [] id;
    id = new char[strlen(ID)+1];
    strcpy(id, ID);
}

int Ficha::get_fila() const {
    return fila;
}

void Ficha::set_fila(const int fila) {
    this->fila = fila;
}

int Ficha::get_columna() const {
    return columna;
}

void Ficha::set_columna(const int columna) {
    this->columna = columna;
}

void Ficha::asigna(char *ident, int fil, int col) {
    set_id(ident);
    set_fila(fil);
    set_columna(col);
}

void Ficha::imprime(ofstream &arch) const {
    char id[100];
    get_id(id);
    arch<<left<<"ID: "<<setw(6)<<id<<left<<"Fila:"<<right<<setw(3)<<fila
        <<left<<" Columna:"<<right<<setw(3)<<columna<<endl;

}


